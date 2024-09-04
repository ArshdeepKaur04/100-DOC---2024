/*
Question "1339. Maximum Product of Splitted Binary Tree" on Leetcode
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product
of the sums of the subtrees is maximized. Return the maximum product of the sums of the two subtrees.
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
    long long ans = 0, totalSum = 0;
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);
        dfs(root);
        return ans % int(1e9+7);
    }

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};