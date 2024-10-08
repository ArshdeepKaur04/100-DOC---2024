/*
Question "979. Distribute Coins in Binary Tree" on Leetcode
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n 
coins in total throughout the whole tree. In one move, we may choose two adjacent nodes and move one coin from one
node to another. A move may be from parent to child, or from child to parent. Return the minimum number of moves
required to make every node have exactly one coin.
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
    int steps = 0;

    int findSteps(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        int l = findSteps(root->left);
        int r = findSteps(root->right);
        steps += abs(l) + abs(r);
        
        return (l + r + root->val-1);
    }

    int distributeCoins(TreeNode* root) {
        findSteps(root);
        return steps;   
    }
};