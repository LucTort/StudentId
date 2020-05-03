//tree implementation
#include "TreeNode.h"

template <class T>
TreeNode<T>::TreeNode()
{
    key = 0;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k)
{
    key = k;
    left = NULL;
    right = NULL;
}

//still needs implementation
