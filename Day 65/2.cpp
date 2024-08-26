/*
Question "946. Validate Stack Sequences" on Leetcode
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the
result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        int n = pushed.size();
        int i=0, j=0;

        while(i < n && j < n) {
            temp.push(pushed[i]);
            while(!temp.empty() && j<n && popped[j] == temp.top()) {
                temp.pop();
                j++;
            }
            i++;
        }

        return temp.empty();
    }
};