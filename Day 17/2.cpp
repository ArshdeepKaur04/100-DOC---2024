/*
Question:
Given a binary search tree (BST) and a value, insert the value into the BST while maintaining its properties.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        // If the tree is empty, create a new node and return it as the root
        return new TreeNode(val);
    }

    if (val < root->val) {
        // If the value to be inserted is less than the current node's value, insert it into the left subtree
        root->left = insertIntoBST(root->left, val);
    } else {
        // If the value to be inserted is greater than or equal to the current node's value, insert it into the right subtree
        root->right = insertIntoBST(root->right, val);
    }

    // Return the root node after insertion
    return root;
}

// Helper function to print the BST in order (for testing purposes)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating the BST as given in the example
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    cout << "BST before insertion: ";
    inorderTraversal(root);
    cout << endl;

    // Insert the value into the BST
    root = insertIntoBST(root, val);

    cout << "BST after insertion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}