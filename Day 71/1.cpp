/*
Question "199. Binary Tree Right Side View" on Leetcode
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes
you can see ordered from top to bottom.
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
    void solve(TreeNode* root, vector <int> &ans, int level) {
        //base case
        if (root == NULL) {
            return;
        }

        //enetered into a new level
        if (level == ans.size()) {
            ans.push_back(root -> val);
        }

        solve(root -> right , ans, level+1);
        solve(root -> left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector <int> ans;
        solve(root, ans, 0);
        return ans;
    }
};