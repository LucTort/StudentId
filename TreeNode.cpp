//tree implementation
#include "TreeNode.h"
#include "DoublyLinkedList.cpp"

template <class T>
TreeNode<T>::TreeNode()
{
    key = 0;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T nodeDataIn)
{
    key = k;
    nodeData = nodeDataIn;
    left = NULL;
    right = NULL;
}

template <class T>
T TreeNode<T>::getNodeData()
{
    return nodeData;
}

//still needs implementation
