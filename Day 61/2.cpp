/*
Question "85. Maximal Rectangle" on Leetcode
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and
return its area.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement (vector<int> arr, int n) {
        stack <int> s;
        s.push(-1);
        vector <int> ans(n);

        for(int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement (vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestArea(vector<int> arr) {
        int n = arr.size();
        int maxArea = INT_MIN;

        vector<int> prev = prevSmallerElement(arr, n);
        vector<int> next = nextSmallerElement(arr, n);

        for(int i=0; i<n; i++) {
            int length = arr[i];
            int breadth;

            if (next[i] == -1) {
                breadth = n - prev[i] - 1;
            } else {
                breadth = next[i] - prev[i] - 1;
            }

            int newArea = length * breadth;
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int maxi = INT_MIN;
        vector<int> height(matrix[0].size(), 0);

        for(int i=0; i<matrix.size(); i++) {
            //to create height array
            for(int j=0; j<height.size(); j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }

            maxi = max(maxi, largestArea(height));
        }

        return maxi;
    }
};