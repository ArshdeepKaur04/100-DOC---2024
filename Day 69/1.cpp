/*
Question "102. Binary Tree Level Order Traversal" on Leetcode
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right,
level by level).
*/

#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
    
        if (!root) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int qLen = q.size();
            vector<int> level;
            
            for (int i = 0; i < qLen; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            
            if (!level.empty()) {
                res.push_back(level);
            }
        }
        
        return res;
    }
};