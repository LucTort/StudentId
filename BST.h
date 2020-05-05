#include "TreeNode.cpp"

template<typename T>

class BST{
    public:
        BST();
        ~BST();
        //virtual ~BST() - when working with template classes
        void insert(int value, T nodeValue); //which in this example is also our key

        //only returns if the value is in the tree
        bool search(int value); //which in this example is also our key
        TreeNode<T>* searchNode(int value);
        bool deleteNode(int k);
        void printStudent();

        bool isEmpty();
        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        TreeNode<T>* getRoot();

        TreeNode<T>* getSuccessor(TreeNode<T> *d);
        void printTree(TreeNode<T> *node);




        // void returnNode(TreeNode<T> *node);

        // void printInfo(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
        DoublyLinkedList<int> *myDoubly = new DoublyLinkedList<int>();
        // int size = myQueue->getSize();
};
