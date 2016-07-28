#include "EPBPlusTree.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <iostream>
using namespace std;
// constructor
BPlusTree::BPlusTree():_root(NULL)
{
    _lower = ceil((float)n/2);      // calculate lower limit
    _upper = n;                     // calculate upper limit
}
// destructor
BPlusTree::~BPlusTree()
{
    if(_root) {
        destroy(_root);
    }
}
// destroy a B+ tree
void BPlusTree::destroy(BPlusTreeNode* node) {
    if(node->_sum == 0) {
        delete node;
        return;
    }
    for(int i = 0; i < node->_sum; i++) {
        destroy(node->_children[i]);
    }
    delete node;
}
// search value
BPlusTree::SearchRes BPlusTree::search(value v) {
    if(!_root) return {NULL, -1, false};

    if(v > _root->_keys[_root->_sum-1]) return {_root, -1, false}; // represent v is larger than the max
    return SearchInNode(_root, v);
}
/*
 * node         @param: searched node
 * v            @param: serached value
 * Summary:
 *      Searching value v in BPlusTreeNode node.
 */
BPlusTree::SearchRes BPlusTree::SearchInNode(BPlusTreeNode* node, value v) {
    int i, pos = -1;    // position
    bool res = false;   // whether value is found
    assert(node && "The node is an empty pointer!!");
    // find the position, annd v can not be larger than max number.
    for(i = 0; i < node->_sum; i++) {
        if(node->_keys[i] >= v) {
            pos = i;
            // although true, if the node is not a leaf, res is not used eventually.
            if(node->_keys[i] == v)
                res = true;
            break;
        }
    }
    if(!node->_children[0]) return {node, pos, res};
    return SearchInNode(node->_children[pos], v);
}
// get a empty node, and all children pointer is NULL
BPlusTree::BPlusTreeNode* BPlusTree::getLeaf() {
    BPlusTreeNode* p = new BPlusTreeNode;
    p->_sum = 0;
    for(int i = 0; i < n+1; i++) p->_children[i] = NULL;
    return p;
}
// insert a value larger than all the current values
bool BPlusTree::insertLargeValue(value v) {
    BPlusTreeNode* node = _root;
    while(node->_children[0]) {
        node->_keys[node->_sum-1] = v;
        node = node->_children[node->_sum-1];

    }
    node->_keys[node->_sum] = v;
    node->_children[node->_sum] = NULL;
    node->_sum++;

    legalizeNode(node);
    return true;
}
/*
 * node         @param: node where value is inserted
 * pos          @param: position where value is insertd into the node
 * v            @param: value to be inserted
 * Summary:
 *      Insert a value in a node
 */
bool BPlusTree::insertInNode(BPlusTreeNode* node, int pos, value v) {
    // move keys backwards
    for(int i = node->_sum; i > pos; i--) {
        node->_keys[i] = node->_keys[i-1];
    }
    node->_keys[pos] = v;   // insert the value
    node->_sum++;       // increase sum
    if(node->_sum > _upper)
        legalizeNode(node);
    return true;
}

// insert v into the tree, if v has existed, return false
bool BPlusTree::insert(value v) {
    // if empty tree
    if(!_root) {
        _root = getLeaf();
        _root->_keys[0] = v;
        _root->_parent = NULL;
        _root->_sum = 1;
        return true;
    }

    SearchRes res = search(v);
    // if v has existed
    if(res._found) return false;
    // insert a  value larger than the max
    if(res._ptr == _root && res._pos == -1) return insertLargeValue(v);
    return insertInNode(res._ptr, res._pos, v);
}
// If max key of node does not exist in the parent, then set the keys
// else just return
void BPlusTree::setMaxKey(BPlusTreeNode* node) {
    // if node is root, just return;
    if(node == _root) return;
    BPlusTreeNode* parent = node->_parent;
    int i;
    // find position of node in parent.
    for(i = 0; i < parent->_sum; i++) {
        if(parent->_children[i] == node) break;
    }
    // if max key of node exists in parent, just return;
    if(node->_keys[node->_sum-1] == parent->_keys[i]) return;
    // if not, set the key.
    else if(node->_keys[node->_sum-1] < parent->_keys[i]) {
        parent->_keys[i] = node->_keys[node->_sum-1] ;
    } else {
        assert(0 && "Error occurs when setting max key!");
    }
    // if set key is max key of parent, then set parent of parent.
    if(i == parent->_sum - 1) setMaxKey(parent);
}
/*
 * node             @param: node where value is deleted from
 * pos              @param: position where value is deleted from the node
 * Summary:
 *      remove a vlue from a node.
 */
bool BPlusTree::deleteInNode(BPlusTreeNode* node, int pos) {
    // move keys forwards
    for(int i = pos; i < node->_sum-1; i++) {
        node->_keys[i] = node->_keys[i+1];
    }
    node->_sum--;

    // if the node's sum is legal
    if(node->_sum >= _lower) {
        // if max value of keys is deleted, so the same key parent should also changed.
        if(pos== node->_sum)
            setMaxKey(node);
    } else  // if illegal
        legalizeNode(node);
    return true;
}
// delete v from the tree, if v does not exist, return false
bool BPlusTree::remove(value v) {
    SearchRes res = search(v);
    // if value dose not exist in the tree, return false
    if(!res._found || !res._ptr) {
        cout<<v<<" is not be found!"<<endl;
        return false;
    }
    return deleteInNode(res._ptr, res._pos);
}
/*
 * ori          @param: original node whose sum is less than _lower
 * Summary:
 *      Judge ori should borrow key from its brother, or need to combine its brother.
 */
void BPlusTree::BorrowOrCombine(BPlusTreeNode* &ori) {
    // if ori is empty.
    if(!ori) return;
    // if ori is root
    if(ori == _root) {
        // if sum root has no key, it is a empty tree
        if(ori->_sum == 0) {
            delete _root;
            _root = NULL;
        }
        // if _root is leaf, just return
        if(ori->_children[0] == NULL) return;
        // else _root is not leaf, and its sum is 1, delete it.
        if(ori->_sum = 1) { // if sum of root'key is 1, then put its only child root.
            _root = ori->_children[0];
            _root->_parent = NULL;
            delete ori;
            ori = _root;
        }
        return;
    }
    BPlusTreeNode* parent = ori->_parent;
    BPlusTreeNode* LBrother, *RBrother;
    int i;
    // find where is ori
    for(i = 0; i < parent->_sum; i++) {
        if(parent->_children[i] == ori) break;
    }
    if(i == 0) {
        LBrother = NULL;
        RBrother = parent->_children[i+1];
    } else if(i == parent->_sum - 1) {
        RBrother = NULL;
        LBrother = parent->_children[i-1];
    } else {
        LBrother = parent->_children[i-1];
        RBrother = parent->_children[i+1];
    }
    // borrow key from right brother
    if(RBrother && RBrother->_sum > _lower) {
        ori->_sum++;
        ori->_keys[ori->_sum-1] = RBrother->_keys[0];
        ori->_children[ori->_sum-1] = RBrother->_children[0];
        // if ori is not leaf, make its new child points to him.
        if(ori->_children[0])
            ori->_children[ori->_sum - 1]->_parent = ori;
        // set max value of ori to parent
        parent->_keys[i] = ori->_keys[ori->_sum-1];
        // if parent->_keys[i] is max value in the node, ist parent's corresponding key
        if(i == parent->_sum - 1) setMaxKey(parent);
        // remove borrowed key from right brother
        for(int j = 0; j < RBrother->_sum - 1; j++ ) {
            RBrother->_keys[j] = RBrother->_keys[j+1];
            RBrother->_children[j] = RBrother->_children[j+1];
        }
        RBrother->_sum--;

        return;
    }
    // borrow key from left brother
    if(LBrother && LBrother->_sum > _lower) {
        // leave space for the borrowed key
        for(int j = ori->_sum; j > 0; j--) {
            ori->_keys[j] = ori->_keys[j-1];
            ori->_children[j] = ori->_children[j-1];
        }
        ori->_sum++;
        // borrow key from left brother
        ori->_keys[0] = LBrother->_keys[LBrother->_sum-1];
        ori->_children[0] = LBrother->_children[LBrother->_sum-1];
        // make children[0] point to ori
        if(ori->_children[0]) ori->_children[0]->_parent = ori;
        LBrother->_sum--;
        // set max key of left brother to its parent
        parent->_keys[i-1] = LBrother->_keys[LBrother->_sum-1];
        // if parent->_keys[i] was ori's max, but now it was deleted, it need change the value
        if(ori->_keys[ori->_sum-1] < parent->_keys[i]) {
            parent->_keys[i] = ori->_keys[ori->_sum-1];
            // if i is the position of parent's last child,
            // corresponding value of parent's parent should be set.
            if(i == parent->_sum - 1) setMaxKey(parent);
        }
        return;
    }
    int leftPosInParent;    // left child in parent
    BPlusTreeNode* L, *R;   // left child, and right child
    if(RBrother) {
        L = ori;
        R = RBrother;
        leftPosInParent = i;
    } else if(LBrother) {
        L = LBrother;
        R = ori;
        leftPosInParent = i - 1;
    } else {
        assert(0 && "Error occurs when combining!");
    }
    // combine R to L, and delete R
    for(int j = 0; j < R->_sum; j++) {
        L->_keys[L->_sum+j] = R->_keys[j];
        L->_children[L->_sum+j] = R->_children[j];
    }

    // if L is not leaf, then make his new children piont to him.
    if(L->_children[0]) {
        for(int j = 0; j < R->_sum; j++) {
            L->_children[L->_sum+j]->_parent = L;
        }
    }
    L->_sum += R->_sum;
    delete R;
    // remove corresponding information of node R from parent
    for(int j = leftPosInParent+1; j < parent->_sum-1; j++) {
        parent->_keys[j] = parent->_keys[j+1];
        parent->_children[j] = parent->_children[j+1];
    }
    parent->_keys[leftPosInParent] = L->_keys[L->_sum-1];
    parent->_sum--;
    // if L node now is the max child of parent,
    // then corresponding value of parent's parent should be set.
    if(leftPosInParent == parent->_sum - 1) setMaxKey(parent);
    // if removed key from parent was ever max key, then
    ori = L;
}
// split node into two nodes
void BPlusTree::split(BPlusTreeNode* &node) {
    // split into two node
    int leftSum = _lower;
    int rightSum = node->_sum -  leftSum;
    BPlusTreeNode* rightNode = getLeaf();
    // move redundant keys into right node.
    for(int i = 0; i < rightSum; i++) {
        rightNode->_keys[i] = node->_keys[leftSum+i];
        rightNode->_children[i] = node->_children[leftSum+i];
    }
    // if rightNode is not leaf, make their children point to him
    if(rightNode->_children[0]) {
        for(int i = 0; i < rightSum; i++)
            rightNode->_children[i]->_parent = rightNode;
    }
    rightNode->_sum = rightSum;
    // "remove" redundant keys from left node
    node->_sum = leftSum;
    // if node is root
    if(node == _root) {
        // create a new root node
        _root = getLeaf();
        _root->_sum=2;
        _root->_keys[0] = node->_keys[node->_sum-1];
        _root->_keys[1] = rightNode->_keys[rightNode->_sum-1];
        _root->_children[0] = node;
        _root->_children[1] = rightNode;
        // specify their parent
        node->_parent = rightNode->_parent = _root;
        _root->_parent=NULL;
        return;
    }
    int pos;
    BPlusTreeNode* parent = node->_parent;
    // find the position where node is in its parent.
    for(pos = 0; pos < parent->_sum; pos++) {
        if(parent->_children[pos] == node) break;
    }
    // leave space for split node
    for(int j = parent->_sum; j > pos; j--) {
        parent->_keys[j] = parent->_keys[j-1];
        parent->_children[j] = parent->_children[j-1];
    }
    // increase parent's sum
    parent->_sum++;
    // specify pointer of position pos in parent to right node
    parent->_children[pos+1] = rightNode;
    // specify value of position pos in parent
    parent->_keys[pos] = node->_keys[node->_sum-1];
    // specify its parent
    rightNode->_parent = parent;
    return;

}
// legalize the node
void BPlusTree::legalizeNode(BPlusTreeNode* node) {
    if(!node) return;
    //if(node->_sum >= _lower && node->_sum <= _upper) return;
    if(node->_sum < _lower ) {
        bool isRoot = node == _root;
        BorrowOrCombine(node);
        if(!isRoot)
            legalizeNode(node->_parent);
        return;
    }
    if(node->_sum > _upper) {
        split(node);
        legalizeNode(node->_parent);
        return;
    }
}
// print the tree
void BPlusTree::printTree() const {
    if(_root) printNode(_root);
    else
        cout<<"B+ Tree is empty!!!!"<<endl;
}
// print keys of a node recursively
void BPlusTree::printNode(BPlusTreeNode* node) const{
    // if leaf node, then return.
    if(!node) return;
    // print all keys of this node
    cout<<"Keys : ";
    for(int i = 0; i < node->_sum; i++) {
        cout<<node->_keys[i]<<", ";
    }
    if(node->_parent) {
        cout<<"------ parent[0] : "<<node->_parent->_keys[0]<<", and parent[1] : "<<node->_parent->_keys[1];
    }
    cout<<endl;
    // print each child node
    for(int i = 0; i < node->_sum; i++) {
        printNode(node->_children[i]);
    }
}
