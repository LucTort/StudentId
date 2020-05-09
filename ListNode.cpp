// //header file for the double linked list
#include "ListNode.h"
template <class T>


//ListNode implementation file (.cpp)
ListNode<T>::ListNode(){
  data=0;
  next = NULL;//nullptr if there are issues
  prev = NULL;
}
template <class T>

ListNode<T>::ListNode(T d){
  data=d;
  next = NULL;
  prev = NULL;
}
template <class T>

ListNode<T>::~ListNode(){
  //we do this part
}
