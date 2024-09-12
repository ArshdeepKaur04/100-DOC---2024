/*
Question "105. Construct Binary Tree from Preorder and Inorder Traversal" on Leetcode
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
is the inorder traversal of the same tree, construct and return the binary tree.
*/

#include <iostream>
#include <vector>
#include <map>
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
    void createMapping(vector<int>& inorder, map<int, int> &nodeToIndex, int n) {
        for(int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &index, int inorderStart, int inorderEnd, 
                int n, map<int, int> &nodeToIndex) {
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];
        
        root->left = solve(inorder, preorder, index, inorderStart, pos-1, n, nodeToIndex);
        root->right = solve(inorder, preorder, index, pos+1, inorderEnd, n, nodeToIndex);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        int n = preorder.size();
        createMapping(inorder, nodeToIndex, n);
        TreeNode* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};