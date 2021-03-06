
#include "DoublyLinkedList.h"

//implementation file for my DoublyLinkedList (.cpp)

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  //empty list
  size = 0;
  front = NULL;
  back = NULL;

}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //build on our own
}
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size==0);
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while (curr != NULL){
    cout << curr -> data;
    if (curr != NULL) {cout << ", ";}
    curr = curr -> next;
  }
  cout << endl;
}
template <class T>
T DoublyLinkedList<T>::peekDoubly(){
  ListNode<T> *curr = back;

  if (front == NULL){
    cout << "The Queue is empty"<< endl;
  }
  return back->data;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T> (d);
  node->data=d;
  if (front != NULL) {
    node->next=front;
    front->prev=node;
    front = node;
    front->prev=NULL;
    ++size;
  } else {
    front = node;
    front->prev=NULL;
    back  = node;
    back->next=NULL;
    ++size;
  }
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T> (d);
  node -> data=d;
    // newNode->data(d);
  if(front==NULL){
    front = node;
    front->prev=NULL;
    back = node;
    front->next = back;
    back->next=NULL;
    back->prev=front;
    ++size;

    } else if(back!=NULL){

      node->prev=back;
      back->next=node;
      node->next=NULL;
      ++size;

    }
    back = node;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if (!(isEmpty())){
    ListNode<T> *node = front;
    T temp = front -> data;

    if (front ->next == NULL){
      //we have one node in the list
      back = NULL;
    }else{
      //there is more than one node in the list
      front -> next->prev = NULL;
    }
    front = front -> next;
    node -> next = NULL;

    delete node;
    size--;
    return temp;
  }
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if (!(isEmpty())){
    ListNode<T> *node = back;
    int temp = back -> data;
    if (back -> prev == NULL){
      front = NULL;
    }else{
      back -> prev -> next = NULL;
    }
    back = back -> prev;
    node -> prev = NULL;

    delete node;
    size--;
    return temp;
  }
}

//does what it says it does
template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos){

  ListNode<T>* temp;
  ListNode<T>* prev;
  temp =front;
  if (pos !=0){
    for(int i=0;i<pos;i++){
        temp=temp->next;
  }
  prev = temp->prev;
  if(temp->next!=NULL){
  prev->next=temp->next;
  temp->next->prev=prev;
  }
  else{
  prev->next=NULL;
  }

  delete temp;
  }  else {
      prev = temp->next;
      prev->prev=NULL;
      delete temp;
      front = prev;
    }
}
//find the value in the list before we can delete
// this does not take in a positiion as a param. it takes a value

template <class T>
T DoublyLinkedList<T>::remove(T val){
  ListNode<T> *curr = front;
  while (curr -> data != val){
    //keep iterating till we find our value
    curr = curr->next;
    if (curr==NULL){
      return 0;
    }
  }
  //we found the val, now lets delete it
  if (curr == front ){
    //check if node is in the front when we deleting it
    front = curr-> next;
  }else{
    //node is not front or back, in the middle
    curr -> prev-> next = curr -> next;
  }
  if (curr == back){
    back = curr -> prev;
  }else {
    curr -> next -> prev = curr -> prev;
  }

  curr -> next = NULL;
  curr -> prev = NULL;
  int temp = curr -> data;
  delete curr;
  size--;
  return temp;

}

template <class T>
bool DoublyLinkedList<T>::search(T value){
  ListNode<T> *curr = front;
    while(curr != NULL)
    {
        if(curr->data == value)
            return true;
        curr = curr->next;
    }

    std::cerr << "No such element in the list \n";
    return false;

}

template <class T>
void DoublyLinkedList<T>::clearList(){

  while(size > 0){
    removeFront();
    size--;
  }

}

//simply returns a copt of the doubly linked list
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>::getSelf()
{
    ListNode<T> *curr = back;
    T currData;
    DoublyLinkedList<T> *copiedList = new DoublyLinkedList<T>();

  while (curr != NULL){
    copiedList->insertFront(curr -> data);
    curr = curr -> prev;
  }
  return *copiedList;
}