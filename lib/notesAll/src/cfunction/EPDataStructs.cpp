#include "EPDataStructs.h"

SearchTree
makeEmpty (SearchTree tree)
{
  if (tree != NULL)
  {
      makeEmpty (tree->left);
      makeEmpty (tree->right);
      delete tree;
    }
  return NULL;
}

Position
find (int val, SearchTree tree)
{
  if (tree == NULL)
    return NULL;
  if (val < tree->val)
    return find (val, tree->left);
  else if (val > tree->val)
      return find (val, tree->right);
  else
      return tree;
}

Position
findMin (SearchTree tree)
{
  if (tree == NULL)
    return NULL;
  else if (tree->left == NULL)
      return tree;
  else
      return findMin (tree->left);
}

Position
findMax (SearchTree tree)
{
  if (tree != NULL)
    while (tree->right != NULL)
      tree = tree->right;
  return tree;
}

SearchTree
insert (int val, SearchTree tree)
{
  if (tree == NULL)
  {
      tree = new TreeNode;
      if (tree == NULL)
          cout << "Out of space !!!" << endl;
      else
      {
          tree->val = val;
          tree->left = tree->right = NULL;
      }
  }  else if (val < tree->val)
      tree->left = insert (val, tree->left);
  else if (val > tree->val)
      tree->right = insert (val, tree->right);
  return tree;
}

SearchTree
Delete (int val, SearchTree tree)
{
  Position tmp;
  if (tree == NULL)
    cout << "Element not found" << endl;
  else if (val < tree->val)
      tree->left = Delete (val, tree->left);
  else if (val > tree->val)
      tree->right = Delete (val, tree->left);
  else if (tree->left && tree->right)
  {
      tmp = findMin (tree->right);
      tree->val = tmp->val;
      tree->right = Delete (tree->val, tree->right);
  }  else
  {
      tmp = tree;
      if (tree->left == NULL)
          tree = tree->right;
      else if (tree->right == NULL)
          tree = tree->left;
      delete tmp;
  }
}

TreeNode* binarytree_find(TreeNode* pNode, int value)
{
    if(NULL == pNode)
        return NULL;
    if(value == pNode->val)
        return pNode;
    else if(value < pNode->val)
        return binarytree_find(pNode->left,value);
    else
        return binarytree_find(pNode->right,value);
}

Node* hash_find(Node* arr[],int mod,int value)
{
    int data = 0;
    int index= data % mod;
    if(NULL == arr[index])
        return NULL;

    Node* pNode = arr[index];
    while(pNode){
        if(value == pNode->data)
            return pNode;
        pNode = pNode->next;
    }
    return pNode;
}
