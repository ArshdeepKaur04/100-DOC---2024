/*
Question "1145. Binary Tree Coloring Game" on Leetcode
Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of 
nodes n in the tree. n is odd, and each node has a distinct value from 1 to n. Initially, the first player names a 
value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player 
colors the node with value x red, and the second player colors the node with value y blue. Then, the players take 
turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, 
blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or 
parent of the chosen node.) If (and only if) a player cannot choose such a node in this way, they must pass their
turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes. You are
the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not 
possible, return false.
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
public:
    int count(TreeNode* root, int x, int &lc, int &rc) {
        if (root == NULL) {
            return 0;
        }

        int left = count(root->left, x, lc, rc);
        int right = count(root->right, x, lc, rc);
        if(root->val == x) {
            lc = left;
            rc = right;
        }

        return left+right+1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int lc = 0, rc = 0;
        count(root, x, lc, rc);

        int nnpex = n - (lc+rc+1);
        int maxi = max(nnpex, max(lc, rc));

        return maxi>(n/2);
    }
};