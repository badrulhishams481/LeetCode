/*

Top 150 Interview Question
Tag: Binary Tree General
Question: 105. Construct Binary Tree from Preorder and Inorder Traversal
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan-v2&envId=top-interview-150
Solution:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/3986683/easy-solution-explanation/?envType=study-plan-v2&envId=top-interview-150 

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "helper.h"

using namespace std;

//#include "helper.h"

// Function to print level order traversal a tree
void printLevelOrder(TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

// Print nodes at a current level
void printCurrentLevel(TreeNode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->val << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n - 1, inorder, 0, m - 1, mp);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
        root->right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

        return root;
    }
};

int main (void)
{
    // Output: [3,9,20,null,null,15,7]
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7}; 
    Solution * sol = new Solution();
    TreeNode * root = sol->buildTree(preorder,inorder);
    printLevelOrder(root);
    return 0;
}