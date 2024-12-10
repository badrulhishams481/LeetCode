/*
Helper functions for binary tree application
*/
#include <iostream>
#include <vector>

using namespace std;

// BFS Binary

// TODO: make a node template

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode * root; // TODO:

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // TODO: insert
    // below is for serial linked list
    // try to do for tree
    void insert(int val)
    {
        TreeNode* newNode = new TreeNode(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        TreeNode * temp = root;
        while (temp->root != nullptr) {
            temp = temp->root;
        }
        temp->root = newNode;
    }

    // Function to print the linked list
    void printList()
    {
        TreeNode * temp = root;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->right; // temp->next
        }
        cout << endl;
    }
};

// Function to print level order traversal a tree
void printLevelOrder(TreeNode* root);

// Print nodes at a current level
void printCurrentLevel(TreeNode* root, int level);

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(TreeNode* node);

void printRightList(TreeNode * node)
{
    TreeNode * temp = node;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->right; // temp->next
    }
    cout << endl;
}


// Timer
void startTimerInMicroSeconds();
void stopTimerInMicroSeconds();
//uSEC getEcecTimeInMicroSeconds();