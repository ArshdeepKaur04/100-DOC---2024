/*
Question "116. Populating Next Right Pointers in Each Node" on Leetcode
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should 
be set to NULL.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        Node* current = root;

        while(current->left != NULL) {
            Node* temp = current;
            while(current != NULL) {
                current->left->next = current->right;
                current->right->next = current->next==NULL?NULL:current->next->left;
                current = current->next;
            }
            current = temp->left;
        }

        return root;
    }
};