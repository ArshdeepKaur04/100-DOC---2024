/*
Question "129. Sum Root to Leaf Numbers" on Leetcode
You are given the root of a binary tree containing digits from 0 to 9 only. Each root-to-leaf path in the tree 
represents a number. Return the total sum of all root-to-leaf numbers.
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
    int ans = 0;

    void dfs(TreeNode* root, int val) {
        if(!root) {
            return;
        }

        val *= 10;
        val += root->val;

        if(!root->left && !root->right) {
            ans += val;
            return;
        }

        dfs(root->right, val);
        dfs(root->left, val);
    }

    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
};