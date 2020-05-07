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

  if (node->key == root->key && myDoubly->getSize()>0){
    myDoubly->clearList();
  }
    printTree(node->left);
    myDoubly->insertBack(node->key);
    cout << node->key << endl;
    printTree(node->right);

}

template<typename T>
void BST<T>::printStudent(){
  TreeNode<Person*> *studNode= new TreeNode<Person*>();
  Person *currentStud = new Person();
  int peeker = 0;
  double GPA = 0;
  string major = "";
  string standing = "";
  string name = "";
  myDoubly->printList();

  while (myDoubly->getSize() != 0){

    peeker = myDoubly->removeFront();

    studNode = searchNode(peeker);

    currentStud = studNode->getNodeData();

    GPA = currentStud->getGPA();
    major = currentStud->getMajor();
    standing = currentStud ->getStanding();
    name = currentStud->getName();

    cout << " " << endl;
    // cout << "Name: "<< name << endl;
    // cout << "ID: " << peeker << endl;
    // cout << "GPA: " << GPA << endl;
    // cout << "Major: "<< major<<endl;
    // cout << "Standing: "<< standing<< endl;

    currentStud->printStudData();
  }









}

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
                    root = NULL;
                }
                else if(isLeft)
                {
                    // cout << parent->left->key<<endl;
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
