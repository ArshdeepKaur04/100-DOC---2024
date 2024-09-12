/*
Question "124. Binary Tree Maximum Path Sum" on Leetcode
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge
connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass
through the root. The path sum of a path is the sum of the node's values in the path. Given the root of a binary
tree, return the maximum path sum of any non-empty path.
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
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;

        // Calculate maximum path sum on the left and right subtrees
        int leftMax = dfs(root->left, res);
        int rightMax = dfs(root->right, res);

        // If the maximum sum is negative, we ignore that branch by considering it as 0
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        // Update the result for the current node by including both left and right paths
        res = max(res, root->val + leftMax + rightMax);

        // Return the maximum path sum from the current node either to the left or right child
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;

        // Start the DFS traversal from the root
        dfs(root, res);
        return res;
    }
};