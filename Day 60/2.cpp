/*
Question "739. Daily Temperatures" on Leetcode
Given an array of integers temperatures represents the daily temperatures, return an array answer such that
answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no
future day for which this is possible, keep answer[i] == 0 instead.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); ++i) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto [stackT, stackInd] = stack.top();
                stack.pop();
                res[stackInd] = i - stackInd;
            }
            stack.push({t, i});
        }

        return res;
    }
};