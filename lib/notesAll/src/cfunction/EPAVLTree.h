#ifndef EPAVLTREE_H
#define EPAVLTREE_H
#include <iostream>
using namespace std;
//AvlTree.h
#pragma once
//AvlTreeNode平衡二叉树节点
template <class T>
class AvlTreeNode
{
public:
       AvlTreeNode<T> *left;
       AvlTreeNode<T> *right;
       AvlTreeNode<T> *parent;
       int balanceFactor;//平衡因子
       T data;
       AvlTreeNode(const T& item, AvlTreeNode<T>* lptr=NULL, AvlTreeNode<T>* rptr=NULL, AvlTreeNode<T>* par=NULL, int balfac=0);
       void inorder();
};
//AvlTree平衡二叉树
template <class T>
class AvlTree
{
public:
       AvlTreeNode<T>* root;
       AvlTreeNode<T>* current;
       int size;
       AvlTreeNode<T>* LL(AvlTreeNode<T>* tree);
       AvlTreeNode<T>* LR(AvlTreeNode<T>* tree);
       AvlTreeNode<T>* RR(AvlTreeNode<T>* tree);
       AvlTreeNode<T>* RL(AvlTreeNode<T>* tree);
       void buildParent(AvlTreeNode<T>* tree);

       bool RotateSubTree(AvlTreeNode<T>* tree);
       AvlTree(void);
       AvlTreeNode<T>* Search(const T item);
       bool Insert(T item);
       bool Delete(T item);
       void Destory(AvlTreeNode<T>* tree);
       ~AvlTree(void);
       void inorder();
};
 void showAvl();
#endif // EPAVLTREE_H
