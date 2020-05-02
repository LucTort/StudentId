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
            parent = current;


            if(k < current->key)
            {
                cout << current->key << endl;
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
                cout << current->key << endl;
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
                    cout << parent->left->key<<endl;
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
                TreeNode *successor = getSuccessor(current);

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
