/*
Question "Image Multiplication" on GeeksForGeeks
You are given a binary tree. Your task is pretty straightforward. You have to find the sum of the product of each
node and its mirror image (The mirror of a node is a node which exists at the mirror position of the node in 
opposite subtree at the root.). Don’t take into account a pair more than once. The root node is the mirror image of
itself.
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
    long long mod = 1000000007;
    
    void solve(Node* root,Node* root1,long long &sum) {
        if(!root || !root1) {
            return;
        }

        sum += (root->data * root1->data);
        sum %= mod;

        solve(root->left,root1->right,sum);
        solve(root->right,root1->left,sum);
    }
    
    long long imgMultiply(Node *root) {
        long long sum = 0;

        solve(root->left, root->right, sum);
        sum += (root->data * root->data);
        sum %= mod;

        return sum;
    }
};