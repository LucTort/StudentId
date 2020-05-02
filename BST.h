#include "TreeNode.cpp"

class BST{
    public:
        BST();
        ~BST();
        //virtual ~BST() - when working with template classes
        void insert(int value); //which in this example is also our key

        //only returns if the value is in the tree
        bool search(int value); //which in this example is also our key
        TreeNode* searchNode(int value);
        bool deleteNode(int k);

        bool isEmpty();
        TreeNode* getMin();
        TreeNode* getMax();

        TreeNode* getSuccessor(TreeNode *d);
        void printTree(TreeNode *node);

    private:
        TreeNode *root;
};
