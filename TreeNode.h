#include <cstdlib>
#include <stdexcept>
#include <iostream>

using namespace std;


class TreeNode{
    public:
        TreeNode();
        TreeNode(int key);
            //could also
        //TreeNode(int key, <type> value)
        ~TreeNode();
        //when working with template classes
        // virtual ~TreeNode();

        int key;
        TreeNode *left;
        TreeNode *right;

};  //never forget!
