#ifndef EPDATASTRUCTS_H
#define EPDATASTRUCTS_H
/**
    数据结构的特性
    (1)     数组
    优点：插入块，如果知道下标，可以非常快的存储。
    缺点：查找慢，删除慢，大小固定
    (2)     有序数组
    优点：比无序数组查找快
    缺点：删除和插入慢，大小固定
    (3)     栈
    优点：提供后进先出方式的存取，
    缺点：效率低
    (4)     队列
    优点：提供先进先出的方式存取
    缺点：效率低
    (5)     链表
    优点：插入，删除快
    缺点：查找慢
    (6)     二叉树
    优点：查找，插入，删除都快
    缺点：删除的算法复杂
    (7)     红黑树
    优点：查找，插入，删除都快
    缺点：算法复杂
    (8)     哈希表：
    优点：如果关键字已知则存取极快，插入块
    缺点：删除慢，如果不知道关键字则存取很慢，对存储空间使用不充分。
    (9)     堆
    优点：插入，删除快，对最大数据项的存取很快
    缺点：对其他存储项很慢
    数据结构：数据在计算机内存空间中或磁盘空间中的组织形式。
    算法：完成特定任务的过程、
  */
#include <iostream>
using namespace std;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree makeEmpty (SearchTree tree);
Position find (int val, SearchTree tree);
Position findMin (SearchTree tree);
Position findMax (SearchTree tree);
SearchTree insert (int val, SearchTree tree);
SearchTree Delete (int val, SearchTree tree);
int retrieve (Position p);

struct TreeNode
{
  int val;
  SearchTree left;
  SearchTree right;
};

TreeNode* binarytree_find(TreeNode* pNode, int value);

struct Node
{
    int data;
    Node* next;
};
Node* has_find(Node* arr[],int mod,int value);

#endif // EPDATASTRUCTS_H
