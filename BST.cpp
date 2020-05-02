//still needs to be completed\

#include "BST.h"


BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    //do it yo'self
}

void BST::printTree(TreeNode *node)
{
    if (node == NULL)
        {return;}

    printTree(node->left);
    cout << node->key << endl;
    printTree(node->right);
}

TreeNode* BST::getMax()
{
    TreeNode *curr = root;

    if (root == NULL)
        {return NULL;} //empty tree

    while(curr->right != NULL)
    {
        curr = curr->right;
    }

    return curr;

  } // or curr->key to get the value

  TreeNode* BST::getMin()
  {
      TreeNode *curr = root;

      if (root == NULL)
          {return NULL;} //empty tree

      while(curr->left != NULL)
      {
          curr = curr->left;
      }

      return curr;

    } // or curr->key to get the value

    bool BST::isEmpty()
    {
        return (root == NULL);
    }

    void BST::insert(int value)
{
    TreeNode *node = new TreeNode(value); //value is also the key

    if(root == NULL)
    {
        //we have an empty tree
        root = node;
    }
    else
    {
        //tree is not empty, we need to find the location
        TreeNode *curr = root;
        TreeNode *parent; //empty node

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

    bool BST::search(int value)
    {
        if(isEmpty())
            {false;}
        else
        {
            //tree not empty :P
            TreeNode *current = root;

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


    TreeNode* BST::searchNode(int value)
    {
        if(isEmpty())
            {cout << "The tree is empty"<< endl;}
        else
        {
            //tree not empty :P
            TreeNode *current = root;

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
                    {cout << "The node doesn't exist"<< endl;}

            }
            cout << "The node doesn't exist"<< endl;
        }
    }//end of search

    bool BST::deleteNode(int k)
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
        TreeNode *current = root;
        TreeNode *parent = root;
        bool isLeft = true;

        //usual code to find TreeNode
        //we will also update pointers
        while(current->key != k)    //stops when finds node to delete
        {
            cout << "parent = current: "<< current -> key<< endl;
            cout << "Operation 1 started" << endl;
            parent = current;
            cout << "Operation 1 finished" << endl;


            if(k < current->key)
            {
                cout << "Operation 2 started" << endl;
                cout << current->key << endl;
                isLeft = true;
                current = current->left;
                cout << "Operation 2 finished" << endl;
            }else
            {
                cout << "Operation 3 started" << endl;
                isLeft = false;
                current = current->right;
                cout << "Operation 3 finished" << endl;
            }

            if(current == NULL)
            {
                cout << "Operation 4 started" << endl;
                return false;
                cout << "Operation 4 finished" << endl;
            }
                cout << "Operation 5 started" << endl;
                cout << current->key << endl;
                cout << "Operation 5 finished" << endl;
        }

            //if we made here, then we've found the node now let's proceed to deleteNode

            //no children, leaf TreeNode
            if(current->left == NULL && current->right == NULL)
            {
                cout << "Operation 6 started" << endl;
                if(current == root)
                {
                  cout << "sf"<< endl;
                    root = NULL;
                }
                else if(isLeft)
                {
                    cout << "sf fffs"<< endl;
                    cout << parent->left->key<<endl;
                    parent->left = NULL;
                    cout << "sf fffs x@"<< endl;
                    cout <<"current key: " <<current -> key<< endl;
                }
                else
                {
                  cout << "sf feedss"<< endl;
                    parent->right = NULL;
                }

                cout << "Operation 6 finished" << endl;
            }
            
            // else if(parent->left == NULL)
            //     {cout << current->right->key << endl;}
 
            
            // cout << "POOP"<< endl;
            //one child and the child is isLeft
            
            else if(current->right == NULL)
            {

                cout << "Operation 7 started" << endl;
                //does not have a right child
                if(current == root)
                {
                    root = current->left;
                }
                else if(isLeft)
                {
                    cout << "here is the prob"<< endl;
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->right;
                }
                cout << "Operation 7 finished" << endl;
            }

            else if(current->left == NULL)
            {
                cout << "Operation 8 started" << endl;
                //does not have a left child
                if(current == root)
                {
                    root = current->right;
                }
                else if(isLeft)
                {
                  cout << "prob"<< endl;
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
                cout << "Operation 8 finished" << endl;
            }
            else
            {
              cout << "Operation started 3"<< endl;
                //the node has 2 children
                TreeNode *successor = getSuccessor(current);

                if(current == root)
                {
                    cout << "Operation 9 started" << endl;
                    root = successor;
                    cout << "Operation 9 finished" << endl;
                }
                else if(isLeft)
                {
                    cout << "Operation 10 started" << endl;
                    parent->left = successor;
                    cout << "Operation 10 finished" << endl;
                }
                else
                {
                    cout << "Operation 11 started" << endl;
                    parent->right = successor;
                    cout << "Operation 11 finished" << endl;
                }

                cout << "Operation 12 started" << endl;
                successor->left = current->left;
                cout << "Operation 12 finished" << endl;

                return true;
            }

            cout << "End of function" << endl;
    }

    TreeNode* BST::getSuccessor(TreeNode *d)
    {
        //d is the node to be deleted

        TreeNode *sp = d;
        TreeNode *successor = d;
        TreeNode *current = d->right;

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
