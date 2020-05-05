#include "Person.cpp"

template <class T>


class TreeNode{
    public:
        TreeNode();
        TreeNode(int key, T nodeData);
            //could also
        //TreeNode(int key, <type> value)
        ~TreeNode();
        //when working with template classes
        // virtual ~TreeNode();

        T getNodeData();

        int key;
        T nodeData;
        TreeNode<T> *left;
        TreeNode<T> *right;

};  //never forget!
