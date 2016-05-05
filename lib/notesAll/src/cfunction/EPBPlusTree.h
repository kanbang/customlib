#ifndef EPBPLUSTREE_H
#define EPBPLUSTREE_H
/**
B+树
    B+树是B-树的变体，也是一种多路搜索树：
    1.其定义基本与B-树同，除了：
    2.非叶子结点的子树指针与关键字个数相同；
    3.非叶子结点的子树指针P[i]，指向关键字值属于[K[i], K[i+1])的子树
    （B-树是开区间）；
    5.为所有叶子结点增加一个链指针；
    6.所有关键字都在叶子结点出现；

    B+的搜索与B-树也基本相同，区别是B+树只有达到叶子结点才命中（B-树可以在
    非叶子结点命中），其性能也等价于在关键字全集做一次二分查找；
    B+的特性：
    1.所有关键字都出现在叶子结点的链表中（稠密索引），且链表中的关键字恰好
    是有序的；
    2.不可能在非叶子结点命中；
    3.非叶子结点相当于是叶子结点的索引（稀疏索引），叶子结点相当于是存储
    （关键字）数据的数据层；
    4.更适合文件索引系统；

小结
    B树：二叉树，每个结点只存储一个关键字，等于则命中，小于走左结点，大于
    走右结点；
    B-树：多路搜索树，每个结点存储M/2到M个关键字，非叶子结点存储指向关键
    字范围的子结点；
    所有关键字在整颗树中出现，且只出现一次，非叶子结点可以命中；
    B+树：在B-树基础上，为叶子结点增加链表指针，所有关键字都在叶子结点
    中出现，非叶子结点作为叶子结点的索引；B+树总是到叶子结点才命中；
    B*树：在B+树基础上，为非叶子结点也增加链表指针，将结点的最低利用率
    从1/2提高到2/3；
       */
#define n 4
typedef int value;
class BPlusTree
{
public:
    struct BPlusTreeNode {
        int _sum;                       // sum of the keys
        BPlusTreeNode* _parent;         // parent
        value _keys[n+1];                 // keys array
        BPlusTreeNode* _children[n+2];     // children array, and number n+2 child is pointed to next leaf node
    };
    struct SearchRes {
        BPlusTreeNode* _ptr;            // found node
        int        _pos;            // position where target value should be
        bool       _found;          // whether found
    };
    /*enum BorrowOrCombine {
        RIGHT_BORROW,
        LEFT_BORROW,
        RIGHT_COMBINE,
        LEFT_COMBINE
    };*/
    BPlusTree();
    virtual ~BPlusTree();
    SearchRes search(value v);      // search value
    bool insert(value);             // insert a value into the tree
    bool remove(value);        // delete a value from the tree
    void printTree() const;           // print the  tree.
protected:
    BPlusTreeNode*  _root;          // root of BTree
    unsigned    _upper;             // upper limit for key numver
    unsigned    _lower;             // lower limit for key number
    void destroy(BPlusTreeNode* node);  // destroy  a tree
    SearchRes SearchInNode(BPlusTreeNode*, value);          // search value in a node
    static BPlusTreeNode* getLeaf() ;       // get a leaf node
    bool insertLargeValue(value);           // insert a value larger than all current keys.
    bool insertInNode(BPlusTreeNode*, int, value);          // insert a value into a node
    bool deleteInNode(BPlusTreeNode*, int);          // delete a value from a node
    void legalizeNode(BPlusTreeNode*);               // legalize a node
    void setMaxKey(BPlusTreeNode*);                  // Check max key of a node does exist in its parent.
    void BorrowOrCombine(BPlusTreeNode*&);              // borrow or combine node
    void split(BPlusTreeNode*&);                        // split node into two node
    void printNode(BPlusTreeNode*) const;                     // print node recursively

};

#endif // EPBPLUSTREE_H
