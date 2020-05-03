#include "TreeNode.cpp"

template <class T>

class BST{
    public:
        BST();
        ~BST();
        //virtual ~BST() - when working with template classes
        void insert(int value); //which in this example is also our key

        //only returns if the value is in the tree
        bool search(int value); //which in this example is also our key
        TreeNode<T>* searchNode(int value);
        bool deleteNode(int k);

        bool isEmpty();
        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        TreeNode<T>* getRoot();

        TreeNode<T>* getSuccessor(TreeNode<T> *d);
        void printTree(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
};
