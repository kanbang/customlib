#ifndef EPMINUSTREE_H
#define EPMINUSTREE_H
/**
B-树
    是一种多路搜索树（并不是二叉的）：
    1.定义任意非叶子结点最多只有M个儿子；且M>2；
    2.根结点的儿子数为[2, M]；
    3.除根结点以外的非叶子结点的儿子数为[M/2, M]；
    4.每个结点存放至少M/2-1（取上整）和至多M-1个关键字；（至少2个关键字）
    5.非叶子结点的关键字个数=指向儿子的指针个数-1；
    6.非叶子结点的关键字：K[1], K[2], …, K[M-1]；且K[i] < K[i+1]；
    7.非叶子结点的指针：P[1], P[2], …, P[M]；其中P[1]指向关键字小于K[1]的
      子树，P[M]指向关键字大于K[M-1]的子树，其它P[i]指向关键字属于(K[i-1], K[i])的子树；
    8.所有叶子结点位于同一层；

    B-树的特性：
    1.关键字集合分布在整颗树中；
    2.任何一个关键字出现且只出现在一个结点中；
    3.搜索有可能在非叶子结点结束；
    4.其搜索性能等价于在关键字全集内做一次二分查找；
    5.自动层次控制；
    由于限制了除根结点以外的非叶子结点，至少含有M/2个儿子，确保了结点的至少
    利用率，其最底搜索性能为：
    O(min) = O(log2 N)
        其中，M为设定的非叶子结点最多子树个数，N为关键字总数；
        所以B-树的性能总是等价于二分查找（与M值无关），也就没有B树平衡的问题；
        由于M/2的限制，在插入结点时，如果结点已满，需要将结点分裂为两个各占
        M/2的结点；删除结点时，需将两个不足M/2的兄弟结点合并；
 */
#define m 3
typedef int value;
class BTree
{
public:
    struct BTreeNode {
        unsigned    _sum;           // sum of keys
        BTreeNode*  _parent;        // parent of the node
        value       _keys[m+1];     // key array
        BTreeNode*  _children[m+1]; // children pointer
    };
    struct SearchRes {
        BTreeNode* _ptr;            // found node
        int        _pos;            // position where target value should be
        bool       _found;          // whether found
    };
    enum DIRECTION {
        NO_DIRECTION,               // no direction
        RIGHT,                      // right
        LEFT                       // left
    };
    bool insertValue(value v);      // insert value into the tree
    BTree();                        // constructor
    virtual ~BTree();               // destructor
    SearchRes Search(value v);      // search value
    void printTree() const;         // print the tree
    bool deleteValue(value v);      // delete value from the tree
protected:
    BTreeNode*  _root;      // root of BTree
    unsigned    _upper;     // upper limit for key numver
    unsigned    _lower;     // lower limit for key number
    BTreeNode* getLeaf(BTreeNode* parent);  // create a leaf node.
    bool isLowest(BTreeNode* node);         // if node is in lowest layer
    SearchRes SearchInNode(BTreeNode* node, value v);       // search value in the node
    bool insertInNode(BTreeNode*, value, int, BTreeNode*, BTreeNode*);  // insert value in the node
    void split(BTreeNode* &, value&, int&, BTreeNode*&, BTreeNode*&);         // split the node
    void printNode(BTreeNode*) const;               // print the keys of a node
    void deleteInNode(BTreeNode*, int);        // delete value from a node
    // get a value to replace the value to be deleted in a non-lowest node
    BTreeNode* findMinimumNode(BTreeNode* node);         // find the minimum node of the sub tree
    BTreeNode* getRBrother(const BTreeNode*, int& parentPos);               // get right brother
    BTreeNode* getLBrother(const BTreeNode*, int& parentPos);               // get left brother.
    void borrow(BTreeNode*, BTreeNode*, int parentPos, DIRECTION);          // borrow from brother
    void combine(BTreeNode*, BTreeNode*, int parentPos);                    // combine with brother
    void LegalizeNonLowestNode(BTreeNode*);                                 // make non-lowest legal
    void destroy(BTreeNode*);                                               // destory a tree.
};

#endif // EPMINUSTREE_H
