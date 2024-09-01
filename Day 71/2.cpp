/*
Question "Left View of Binary Tree" on GeeksForGeeks
Given a Binary Tree, return its Left view. The left view of a Binary Tree is a set of nodes visible when the tree 
is visited from the Left side. If no left view is possible, return an empty array.
*/

#include <iostream>
#include <vector>
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

void solve(Node* root, vector <int> &ans, int level) {
    //base case
    if (root == NULL) {
        return;
    }

    //enetered into a new level
    if (level == ans.size()) {
        ans.push_back(root -> data);
    }

    solve(root -> left, ans, level+1);
    solve(root -> right , ans, level+1);
}

vector<int> leftView(Node *root) {
    vector <int> ans;
    solve(root, ans, 0);
    return ans;
}