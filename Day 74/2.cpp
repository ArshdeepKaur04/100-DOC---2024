/*
Question "235. Lowest Common Ancestor of a Binary Search Tree" on Leetcode
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else {
                break;
            }
        }

        return root;
    }
};