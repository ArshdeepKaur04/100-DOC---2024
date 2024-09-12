/*
Question "1372. Longest ZigZag Path in a Binary Tree" on Leetcode
You are given the root of a binary tree. Zigzag length is defined as the number of nodes visited - 1. (A single
node has a length of 0). Return the longest ZigZag path contained in that tree.
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
    int maxi = 0;
    
    void rec(TreeNode* root, int dir, int len) {
        if (root == NULL) {
            return;
        }
        maxi = max(maxi, len);

        if (dir == 0) {
            rec(root->left, dir, 1);
            rec(root->right, dir^1, len+1);
        }
        else {
            rec(root->left, dir^1, len+1);
            rec(root->right, dir, 1);
        }
        return;
    }

    int longestZigZag(TreeNode* root) {
        rec(root->left, 0, 1);
        rec(root->right, 1, 1);
        return maxi;
    }
};