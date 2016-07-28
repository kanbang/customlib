#include "EPBinTreeNode.h"
#include <iostream>
using namespace std;

BinTreeNode::BinTreeNode() : key(-1),left(NULL),right(NULL)
{
}

BinTreeNode::BinTreeNode(BinTreeNode *node) : key(node->key), left(node->left),right(node->right)
{
}

BinTreeNode::BinTreeNode(int num) : key(num),left(NULL),right(NULL)
{

}

BinTreeNode::~BinTreeNode()
{

}

int BinTreeNode::getKey()
{
    return key;
}

BinTreeNode* BinTreeNode::getLeft()
{
    return left;
}

BinTreeNode* BinTreeNode::getRight()
{
    return right;
}

void BinTreeNode::inorder()
{
    if(this != NULL)
    {
        this->left->inorder();
        cout<<this->key<<" ";
        this->right->inorder();
    }
}

void BinTreeNode::preorder()
{
    if(this != NULL)
    {
        cout<<this->key <<" ";
        this->left->preorder();
        this->right->preorder();
    }
}

void BinTreeNode::postOrder()
{
    if(this != NULL)
    {
        this->left->postOrder();
        this->right->postOrder();
        cout<<this->key<<" ";
    }
}

void BinTreeNode::makeEmpty()
{
    if(this != NULL)
    {
        this->left->makeEmpty();
        this->right->makeEmpty();
        delete this;
    }
}

int BinTreeNode::getHeight()
{
    int L, R;
    if(this == NULL)
        return 0;
    L = this->left->getHeight();
    R = this->right->getHeight();
    return 1 + (L > R ? L : R);
}

BinTree::BinTree() : root(NULL)
{

}

BinTree::~BinTree()
{
    makeEmpty();
}

void BinTree::makeEmpty()
{
    BinTreeNode* p = root;
    p->makeEmpty();
}

BinTreeNode* BinTree::getRoot()
{
    return root;
}

int BinTree::getKey(BinTreeNode *node)
{
    return node->getKey();
}

int BinTree::getHeight()
{
    return root->getHeight();
}

void BinTree::inorder()
{
    root->inorder();
}

void BinTree::preorder()
{
   root->preorder();
}

void BinTree::postOrder()
{
    root->postOrder();
}

void BinTree::insert(int num)
{
    BinTreeNode* node = new BinTreeNode(num);
    BinTreeNode* p = root, *q;
    if( root == NULL)
    {
        root = node;
        return;
    }
    while(p)
    {
        if(p->key == num)
        {
            cout<<num << " has exist "<<endl;
            return;
        } else if (p->key > num)
        {
            q = p;
            p = p->left;
        } else {
            q = p;
            p = p->right;
        }
    }
    if( q->key > num)
        q->left = node;
    else
        q->right = node;
}

BinTreeNode* BinTree::search(int num)
{
    BinTreeNode* p = root;
    while(p)
    {
        if( p->key == num){
            return p;
        } else if (p->key > num)
        {
            p= p->left;
        } else
            p = p->right;
    }
    cout<<"there is no "<<num<<" in this tree!"<<endl;
    return NULL;
}

int BinTree::Minnum(BinTreeNode *node)
{
    BinTreeNode* p = node;
    while(p->left != NULL)
    {
        p = p->left;
    }
    return p->key;
}

BinTreeNode* BinTree::MinNum(BinTreeNode *node)
{
    BinTreeNode* p = node;
    while(p->left != NULL)
    {
        p = p->left;
    }
    return p;
}
int BinTree::Maxnum(BinTreeNode *node)
{
    BinTreeNode* p = node;
    while(p->right != NULL)
    {
        p = p->right;
    }
    return p->key;
}

BinTreeNode* BinTree::MaxNum(BinTreeNode *node)
{
    BinTreeNode* p = node;
    while(p->right != NULL)
    {
        p = p->right;
    }
    return p;
}

BinTreeNode* BinTree::getParent(BinTreeNode *node)
{
    if(node == root)
        return NULL;
    BinTreeNode*p = root, *q = p;
    while(p)
    {
        if(p->key == node->key)
            return q;
        else if (p->key > node->key)
        {
            q = p;
            p = p->left;
        } else
        {
            q = p;
            p = p->right;
        }
    }
    cout<<"There is no "<<node->key<<" in this tree !"<<endl;
    return NULL;
}

BinTreeNode* BinTree::inorderSuccessor(BinTreeNode *node)
{
    if( node->right != NULL)
        return MinNum(node->right);
    else
    {
        BinTreeNode* p = getParent(node);
        while(p && node == p->right)
        {
            node = p;
            p = getParent(node);
        }
        return p;
    }
}

BinTreeNode* BinTree::inorderPredecessor(BinTreeNode *node)
{
    if( node->left != NULL)
        return MaxNum(node->left);
    else
    {
        BinTreeNode* p = getParent(node);
        while(p && node == p->left)
        {
            node = p;
            p = getParent(node);
        }
        return p;
    }
}

bool BinTree::Delete(int num)
{
    BinTreeNode*p, *q, *t;
    p = search(num);
    if(p == NULL)
        return 0;

    if(p->left == NULL && p->right == NULL)
    {
        q = getParent(p);
        if(p == q->left)
            q->left = NULL;
        else
            q->right = NULL;

        delete p;
        return true;
    } else if (p->left == NULL)
    {
        q = getParent(p);
        if ( p == q->left)
            q->left = p->right;
        else
            q->right = p->right;

        delete p;
        return true;
    } else if (p->right == NULL)
    {
        q = getParent(p);
        if ( p = q->left)
            q->left = p->left;
        else
            q->right = p->left;

        delete p;
        return true;
    } else {
        q = inorderSuccessor(p);
        t = getParent(q);
        t->left = q->right;
        t  = getParent(p);
        if( t->left == p)
            t->left = q;
        else
            t->right = q;

        q->left = p->left;
        q->right = p->right;
        delete p;
        return true;
    }
}

void BinTree::showResult()
{
//    int a[12] = {15,5,3,12,10,13,6,7,16,20,18,23};
    int a[12] = {7,4,10,2,6,8,12,1,3,5,9,11};
    BinTree tree;
    for(int i = 0; i< 12; i++)
        tree.insert(a[i]);
    tree.inorder();
    cout<<endl;
    tree.preorder();
    cout<<endl;
    tree.postOrder();
    cout<<endl;
    cout<<"the height of the tree is : "<<tree.getHeight() <<endl;
    tree.insert(13);
    tree.insert(100);
    tree.inorder();
    cout<<endl;
    tree.search(45);
    if(tree.Delete(5))
        cout<<"delelte "<<5 <<" successfully!"<<endl;
    tree.inorder();
    cout<<endl;
    cout<<"the min num of the tree is :"<<tree.Minnum(tree.getRoot())<<endl;
    cout<<"the max num of the tree is : "<<tree.Maxnum(tree.getRoot())<<endl;
    cout<<"the successor of element 7 is : "<<tree.inorderSuccessor(tree.search(7))->getKey()<<endl;
    cout<<"the predecessor of element 7 is : "<<tree.inorderPredecessor(tree.search(7))->getKey()<<endl;
    cout<<"the successor of element 13 is : "<<tree.inorderSuccessor(tree.search(13))->getKey()<<endl;
}

