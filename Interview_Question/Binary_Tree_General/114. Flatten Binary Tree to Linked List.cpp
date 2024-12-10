/*

Top 150 Interview Question
Tag: Binary Tree General
Question: 105. Construct Binary Tree from Preorder and Inorder Traversal
Link: 
Solution:
*/

#include <iostream>
#include <queue>
#include "helper.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if( root )
        {
            /*Move the left node to the right node*/
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* node = root;
            
            /*Move to the end of the prev left node which is the new right node*/
            while( node->right )
            {
                node = node->right;
            }
            
            /*Append the right node to its end*/
            node->right = temp;
            flatten( root->right ); 
        } 
        return;
               
    }
};

int main (void)
{
    TreeNode * root = new TreeNode(1);
    TreeNode * n1 = new TreeNode(2);
    TreeNode * n2 = new TreeNode(5);
    TreeNode * n3 = new TreeNode(3);
    TreeNode * n4 = new TreeNode(4);
    TreeNode * n5 = new TreeNode(6);

    root->left = n1;
    root->right = n2;
    n1->left = n3; 
    n1->right = n4; 
    n2->right = n5;
    
    Solution * sol = new Solution();
    sol->flatten(root);
    printRightList(root);

    return 0;
}