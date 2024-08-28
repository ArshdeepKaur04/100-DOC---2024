/*
Question "144. Binary Tree Preorder Traversal" on Leetcode
Given the root of a binary tree, return the preorder traversal of its nodes' values.
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
    void preOrder(TreeNode* node, vector<int> &ans) {
        //base case 
        if (node == NULL) {
            return;
        }

        ans.push_back(node -> val);
        preOrder(node -> left, ans);
        preOrder(node -> right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preOrder(root, ans);
        return ans;
    }
};