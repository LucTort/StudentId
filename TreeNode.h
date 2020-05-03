#include <cstdlib>
#include <stdexcept>
#include <iostream>

#include "Person.cpp"

using namespace std;

template <class T>


class TreeNode{
    public:
        TreeNode();
        TreeNode(int key);
            //could also
        //TreeNode(int key, <type> value)
        ~TreeNode();
        //when working with template classes
        // virtual ~TreeNode();

        int key;
        TreeNode<T> *left;
        TreeNode<T> *right;

};  //never forget!
