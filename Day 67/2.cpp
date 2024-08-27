/*
Question "94. Binary Tree Inorder Traversal" on Leetcode
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

#include <iostream>
#include <vector>
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
    void inorder(TreeNode* node, vector<int> &ans) {
        //base case 
        if (node == NULL) {
            return;
        }

        inorder(node -> left, ans);
        ans.push_back(node -> val);
        inorder(node -> right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);
        return ans;
    }
};