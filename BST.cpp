//still needs to be completed\

#include "BST.h"

template<typename T>
BST<T>::BST()
{
    root = NULL;
}

template<typename T>
BST<T>::~BST()
{
    //do it yo'self
}

template<typename T>
void BST<T>::printTree(TreeNode<T> *node)   //create function silimar to this to grab all the nodes in the tree
{

  if (node == NULL)
      {return;}

  if (node->key == root->key && treeNodeIds->getSize()>0){
    // treeNodeIds->clearList();
  }
    printTree(node->left);
    // treeNodeIds->insertBack(node->key);
    cout << node->key << endl;
    printTree(node->right);

}

template<typename T>
void BST<T>::printStudent(){
  TreeNode<T> *studNode = new TreeNode<T>();
  Person *currentStud = new Person();
  DoublyLinkedList<int> *placeHolderList = new DoublyLinkedList<int>;
  *placeHolderList = treeNodeIds->getSelf();
  int peeker = 0;
  double GPA = 0;
  string major = "";
  string standing = "";
  string name = "";


  while (placeHolderList->getSize() > 0){

    peeker = placeHolderList->removeFront();

    studNode = searchNode(peeker);

    currentStud = studNode->getNodeData();

    GPA = currentStud->getGPA();
    major = currentStud->getMajor();
    standing = currentStud ->getStanding();
    name = currentStud->getName();

    cout << " " << endl;

    currentStud->printStudData();
  }

//   cout << "Its size: " <<treeNodeIds->getSize() << endl;
}

template<typename T>
void BST<T>::printFac(){
  TreeNode<T> *facNode= new TreeNode<T>();
  Person *currentFac = new Person();
  DoublyLinkedList<int> *tempDoubly = new DoublyLinkedList<int>;
  *tempDoubly = treeNodeIds->getSelf();
  int peeker = 0;
  // DoublyLinkedList *advisees;//?????????

  tempDoubly->printList();


  while (tempDoubly->getSize() != 0){

    peeker = tempDoubly->removeFront();

    facNode = searchNode(peeker);

    currentFac = facNode->getNodeData();

    cout << " " << endl;

    currentFac->printFacData();

  }

}//end of PrintFac

template<typename T>
TreeNode<T>* BST<T>::getMax()
{
    TreeNode<T> *curr = root;

    if (root == NULL)
        {return NULL;} //empty tree

    while(curr->right != NULL)
    {
        curr = curr->right;
    }

    return curr;

  } // or curr->key to get the value

  template<typename T>
TreeNode<T>* BST<T>::getRoot()
{
    return root;
}

template<typename T>
  TreeNode<T>* BST<T>::getMin()
  {
      TreeNode<T> *curr = root;

      if (root == NULL)
          {return NULL;} //empty tree

      while(curr->left != NULL)
      {
          curr = curr->left;
      }

      return curr;

    } // or curr->key to get the value

template<typename T>
    bool BST<T>::isEmpty()
    {
        return (root == NULL);
    }

template<typename T>
void BST<T>::insert(int value, T nodeValue)
{
    TreeNode<T> *node = new TreeNode<T>(value, nodeValue); //value is also the key

    if(root == NULL)
    {
        //we have an empty tree
        root = node;
        treeNodeIds->insertFront(value);
    }
    else
    {
        //tree is not empty, we need to find the location
        TreeNode<T> *curr = root;
        TreeNode<T> *parent; //empty node

        while(true)
        {
            //let's find the insertion point
            parent = curr;

            if(value < curr->key)
            {
                //go left
                curr = curr->left;
                if(curr == NULL)
                {
                    parent->left = node;
                    treeNodeIds->insertFront(value);
                    break;
                }
            }
            else
            {
                //go right
                curr = curr->right;
                if(curr == NULL)
                {
                    //we found the nodes home
                    parent->right = node;
                    treeNodeIds->insertFront(value);
                    break;
                }
            }
        }
    }
}

template<typename T>
    bool BST<T>::search(int value)
    {
        if(isEmpty())
            {false;}
        else
        {
            //tree not empty :P
            TreeNode<T> *current = root;

            if (root->key == value){
              return current;
            }

            while(current->key != value)
            {
                if(value < current->key)
                {

                    if(current->left == NULL)
                        {
                            return false;
                        }
                    current = current->left;
                    if (current->key == value)
                        {
                            return true;
                            }
                }
                else if(value > current->key)
                    {
                        if(current->right == NULL)
                        {
                            return false;
                        }
                        current = current->right;
                        if (current->key == value)
                        {
                            return true;
                        }
                    }
                if(current == NULL)
                    {return false;}
            }
            return false;
        }
    }//end of search

template <typename T>
    TreeNode<T>* BST<T>::searchNode(int value)
    {
        if(isEmpty())
            {cout << "The tree is empty"<< endl;}
        else
        {
            //tree not empty :P
            TreeNode<T> *current = root;

            if (root->key == value){
              return current;
            }

            while(current->key != value)
            {
                if(value < current->key)
                {
                    current = current->left;
                    if (current->key == value){
                      return current;
                    }
                }
                else
                    {
                        current = current->right;
                        if (current->key == value){
                          return current;
                        }
                    }

                if(current == NULL)
                    {cout << "The node doesn't exist."<< endl;}

            }
            cout << "The node doesn't exist"<< endl;
        }
    }//end of search

template <typename T>
    bool BST<T>::deleteNode(int k)
    {
        cout << "removed: " << treeNodeIds->remove(k) << endl << endl << "Look at me"<< endl;
        if(isEmpty())
        {
            return false;
        }
        else if(!search(k))
        {
            return false;
        }

        //tree is not empty and value exists
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;
        bool isLeft = true;

        //usual code to find TreeNode
        //we will also update pointers
        while(current->key != k)    //stops when finds node to delete
        {
            parent = current;


            if(k < current->key)
            {
                // cout << current->key << endl;
                isLeft = true;
                current = current->left;
            }else
            {
                isLeft = false;
                current = current->right;
            }

            if(current == NULL)
            {
                return false;
            }
                // cout << current->key << endl;
        }

            //if we made here, then we've found the node now let's proceed to deleteNode

            //no children, leaf TreeNode
            if(current->left == NULL && current->right == NULL)
            {
                if(current == root)
                {
                    // cout << "removed: " << treeNodeIds->remove(k) << endl << endl << "Look at me"<< endl;
                    root = NULL;
                    
                }
                else if(isLeft)
                {
                    // cout << "removed: " << treeNodeIds->remove(k) << endl << endl << "Look at me"<< endl;
                    parent->left = NULL;
                    
                }
                else
                {
                    
                    parent->right = NULL;
                }

            }

            // else if(parent->left == NULL)
            //     {cout << current->right->key << endl;}


            // cout << "POOP"<< endl;
            //one child and the child is isLeft

            else if(current->right == NULL)
            {

                //does not have a right child
                if(current == root)
                {
                    root = current->left;
                }
                else if(isLeft)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->right;
                }
            }

            else if(current->left == NULL)
            {
                //does not have a left child
                if(current == root)
                {
                    root = current->right;
                }
                else if(isLeft)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
            }
            else
            {
                //the node has 2 children
                TreeNode<T> *successor = getSuccessor(current);

                if(current == root)
                {
                    root = successor;
                }
                else if(isLeft)
                {
                    parent->left = successor;
                }
                else
                {
                    parent->right = successor;
                }

                successor->left = current->left;

                // cout << "removed: " << treeNodeIds->remove(k) << endl << endl << "Look at me"<< endl;
                return true;
            }
    }

template<typename T>
    TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)
    {
        //d is the node to be deleted

        TreeNode<T> *sp = d;
        TreeNode<T> *successor = d;
        TreeNode<T> *current = d->right;

        while(current != NULL)
        {
            sp = successor;
            successor = current;
            current = current->left;
        }

        if(successor != d->right)
        {
            sp->left = successor->right;
            successor->right = d->right;
        }

        return successor;
    }//end of get successor

template<typename T>
DoublyLinkedList<T> BST<T>::getListOfNodes(){
    // cout << "YEETHAW" << endl;
  TreeNode<T> *studTreeNode = new TreeNode<T>();
  Person *studPersonNode = new Person();
  DoublyLinkedList<int> *tempNodeIds = new DoublyLinkedList<int>;
  DoublyLinkedList<T> *returnedNodes = new DoublyLinkedList<T>;
  *tempNodeIds = treeNodeIds->getSelf();
//   cout << "Nodes in BST: " <<tempNodeIds->getSize() << endl;
  int currentStudId;

//   cout << "Size in getListOfNodes: " << tempNodeIds->getSize()<< endl;
    cout << "Try me" << endl;
  while (tempNodeIds->getSize() > 0){


      cout << "Size: " <<tempNodeIds->getSize() << endl <<"Temp node ids: "<< endl;
      tempNodeIds->printList();

    cout << "Before remove front" << endl;
    currentStudId = tempNodeIds->removeFront();
    cout << "After remove front" << endl;

    studTreeNode = searchNode(currentStudId);
    studPersonNode = studTreeNode->getNodeData();
    cout << studPersonNode->getId() << endl;
    cout << "Before print node" << endl;

    returnedNodes->insertFront(studPersonNode);
    cout << "After insert" << endl;
  }
    cout << "Blah" << endl;
//   cout << "Size in getListOfNodes: " << tempNodeIds->getSize()<< endl;
//   cout << "Size of returned nodes: " << returnedNodes->getSize()<< endl;

  return *returnedNodes;
}

template<typename T>
void BST<T>::insertTreeNodeIds(int d)
{
    treeNodeIds->insertFront(d);
}