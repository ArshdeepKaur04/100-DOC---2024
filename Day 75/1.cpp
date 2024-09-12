/*
Question "LCA in Binary Tree" on GeeksForGeeks
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common
ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them 
are present.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    Node* lca(Node* root ,int n1 ,int n2 ) {
        if (root == NULL) {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2) {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        else {
            return NULL;
        }
    }
};