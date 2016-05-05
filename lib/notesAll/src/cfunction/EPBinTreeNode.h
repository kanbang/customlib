#ifndef EPBINTREENODE_H
#define EPBINTREENODE_H

class BinTree;

class BinTreeNode
{
public:
    BinTreeNode();
    BinTreeNode(BinTreeNode* node);
    BinTreeNode(int num);
    ~BinTreeNode();

    BinTreeNode* getLeft();
    BinTreeNode* getRight();

    int getKey();
    void inorder();
    void preorder();
    void postOrder();
    void makeEmpty();
    int   getHeight();

private:
    friend class BinTree;
    int      key;
    BinTreeNode* left;
    BinTreeNode* right;

};

class BinTree
{
public:
    BinTree();
    ~BinTree();

    void makeEmpty();
    int   getKey(BinTreeNode* node);
    BinTreeNode* getRoot();
    int   getHeight();
    void inorder();
    void preorder();
    void postOrder();
    void insert(int num);
    BinTreeNode* search(int num);
    int Minnum(BinTreeNode* node);
    BinTreeNode* MinNum(BinTreeNode* node);
    int Maxnum(BinTreeNode *node);
    BinTreeNode* MaxNum(BinTreeNode* node);
    BinTreeNode* getParent(BinTreeNode* node);
    BinTreeNode* inorderSuccessor(BinTreeNode* node);
    BinTreeNode* inorderPredecessor(BinTreeNode* node);
    bool Delete(int num);

    static void showResult();
private:
    BinTreeNode* root;
};

#endif // EPBINTREENODE_H
