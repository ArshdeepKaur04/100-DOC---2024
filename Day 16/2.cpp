/*
Question:
You are given a binary tree in the form of a list of integers representing the level-order traversal of the tree.
Your task is to construct the binary tree from the given level-order traversal and then perform an inorder
traversal on it. The inorder traversal should be printed as a list of node values.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode *root, vector<int> &result) {
    if (!root)
        return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

TreeNode *buildTree(const vector<int> &nodes) {
    if (nodes.empty())
        return NULL;
    TreeNode *root = new TreeNode(nodes[0]);
    queue<TreeNode *> q;
    q.push(root);
    for (size_t i = 1; i < nodes.size();) {
        TreeNode *current = q.front();
        q.pop();
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int main() {
    cout << "Enter the values of the nodes in level order (use -1 for NULL nodes):" << endl;
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<int> nodes;
    int val;
    while (iss >> val) {
        nodes.push_back(val);
    }

    TreeNode *root = buildTree(nodes);
    vector<int> result;
    inorderTraversal(root, result);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}