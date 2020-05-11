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
        // void printStudent();
        void printStudent(TreeNode<T> *node);
        void printFac(TreeNode<T> *node);;

        bool isEmpty();
        TreeNode<T>* getMin();
        TreeNode<T>* getMax();
        TreeNode<T>* getRoot();

        TreeNode<T>* getSuccessor(TreeNode<T> *d);
        void printTree(TreeNode<T> *node);


        DoublyLinkedList<T> getListOfNodes();

        void insertTreeNodeIds(int);

        void setTreeNodeIds(DoublyLinkedList<int> *doublyList);
        DoublyLinkedList<int> getTreeNodeIds();
        void loadFromListOfNodes(DoublyLinkedList<Person*> *listOfNodes);
        // void addNodesToDoublyLinkedList(TreeNode<T*> *node, DoublyLinkedList<T*> *doublyList);

        




        // void returnNode(TreeNode<T> *node);

        // void printInfo(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
        DoublyLinkedList<int> *treeNodeIds = new DoublyLinkedList<int>();
};
