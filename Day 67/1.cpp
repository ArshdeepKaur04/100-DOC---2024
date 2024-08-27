/*
Question "1130. Minimum Cost Tree From Leaf Values" on Leetcode
Given an array arr of positive integers, consider all binary trees such that:
- Each node has either 0 or 2 children;
- The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
- The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, 
respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer. A node is a leaf if and only if it has zero children.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
        vector<vector<int>> maxVal(n, vector<int>(n, 0));

        // Initialize maxVal table
        for (int i = 0; i < n; ++i) {
            maxVal[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
            }
        }

        // Initialize dp table for subarrays of length 1 (base case)
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        // Fill dp table for subarrays of increasing lengths
        for (int len = 2; len <= n; ++len) {
            for (int left = 0; left <= n - len; ++left) {
                int right = left + len - 1;
                for (int i = left; i < right; ++i) {
                    long long leftCost = dp[left][i];
                    long long rightCost = dp[i + 1][right];
                    long long currentCost = (long long)maxVal[left][i] * maxVal[i + 1][right];

                    // Prevent overflow and update dp
                    if (leftCost != LLONG_MAX && rightCost != LLONG_MAX) {
                        if (currentCost <= LLONG_MAX - (leftCost + rightCost)) {
                            dp[left][right] = min(dp[left][right], currentCost + leftCost + rightCost);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};