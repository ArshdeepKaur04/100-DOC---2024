/*
Question "99. Recover Binary Search Tree" on Leetcode
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were
swapped by mistake. Recover the tree without changing its structure.
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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);

        if (prev != NULL && (root->val < prev->val)) {
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) {
            swap(first->val, last->val);
        }
        else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};