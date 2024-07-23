/*
Question "Remove Half Nodes" on GeeksForGeeks
You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root
node of the modified tree after removing all the half-nodes. Note: The output will be judged by the inorder
traversal of the resultant tree, inside the driver code.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        if (!root) {
            return NULL;
        }
        
        Node* l = RemoveHalfNodes(root->left);
        Node* r = RemoveHalfNodes(root->right);
        
        root->left = l;
        root->right = r;
        
        if(!root->left && root->right) {
            return root->right;
        }
        
        if(root->left && !root->right) {
            return root->left;
        }
        
        return root;
    }
};