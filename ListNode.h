#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <bits/stdc++.h>

using namespace std;


template <class T>

class ListNode{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode();//default
  ListNode(T d);//overloaded
  ~ListNode();
};
