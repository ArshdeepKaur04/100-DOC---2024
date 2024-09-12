/*
Question "114. Flatten Binary Tree to Linked List" on Leetcode
Given the root of a binary tree, flatten the tree into a "linked list"
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function for DFS traversal
    TreeNode* dfs(TreeNode* root) {
        if (!root) return nullptr;

        // Recursively flatten the left and right subtrees
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);

        // If the left subtree exists, we need to rewire the connections
        if (root->left) {
            if (leftTail) leftTail->right = root->right;  // Connect the end of the left subtree to the start of the right subtree
            root->right = root->left;  // Move the left subtree to the right
            root->left = nullptr;  // Set the left child to nullptr
        }

        // Return the last node in the flattened tree
        return rightTail ? rightTail : (leftTail ? leftTail : root);
    }

    void flatten(TreeNode* root) {
        // Start the DFS traversal from the root
        dfs(root);
    }
};