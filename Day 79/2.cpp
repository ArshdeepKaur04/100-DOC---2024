/*
Question "98. Validate Binary Search Tree" on Leetcode
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
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
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_MIN, LONG_MAX);
    }

    bool validBST(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }

        if (root->val >= maxVal || root->val <= minVal) {
            return false;
        }

        return validBST(root->left, minVal, root->val) && validBST(root->right, root->val, maxVal);
    }
};