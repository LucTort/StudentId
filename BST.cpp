//still needs to be completed

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

    return curr; // or curr->key to get the value

    bool BST::isEmpty()
    {
        return (root == NULL);
    }

    void BST::insert(int value)
    {
        TreeNode *node = new TreeNode(value);   //value is also the key

        if (root = NULL)
        {
            //currently an empty tree
            root = node;
        }
        else{
            //tree isn't empty, need to find location

            TreeNode *curr = root;
            TreeNode *parent; //empty node

            while(true)
            {
                //let's find the insertion point
                parent = curr;

                if (value < curr->key) //
                {
                    curr = curr->left;
                    if (curr == NULL)
                    {
                        parent->left = node;
                        break;
                    }else
                        {
                            //go right
                            curr = curr->right;
                            if (curr == NULL){
                                parent->right = node;
                                break;
                            }
                        }
                }
            }
        }
        
    }//end of insert

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
                    current = current->left;
                }
                else
                    {
                        current = current->right;
                    }

                if(current == NULL)
                    {return false;}
                
            }
            return false;
        }
    }//end of search

    bool BST::deleteNode(int k)
    {
        if(isEmpty())
            {return false;}
        else if(!search(k))
            {return false;}

        //tree is not empty, so let's look for the value!

        TreeNode *current = root;
        TreeNode *parent = root;
        bool isLeft = true;
        //usual code to find treenode
        // we will also update pointers
        while(current->key != k)
        {
            parent = current;

            if(k < current->key)
            {
                isLeft = true;
                current = current->left;
            } else
            {
                isLeft = false;
                current = current->right;
            }

            if (current == NULL)
                {return false;}

            //if we made it here, we've found the now so let's got to deleteNode

            //no children, it's a leaf node
            if (current->left == NULL && current->right == NULL)
            {
                if (current == root)
                    {root = NULL;}
                else if (isLeft)
                    {parent->left = NULL;}
                else
                    {parent->right = NULL;}
                
            }
            //one child and the child is left
            else if(current->right == NULL) //doesn't have right child
                {}

                if (current == root)
                    {root = current->left;}
                else if (isLeft)
                    {parent->left = current->left;}
                else 
                    {parent->right = current->right;}
        }
        else
        {
            //the node has 2 children
            TreeNode *successor = getSuccessor(current);

            if(current == root)
                {root = successor;}
            else if(isLeft)
                {parent->left = successor;}
            else
            {
                parent->right = successor;
            }

            successor->left = current->left;

            return true;
        }

    }//end of delete

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

}