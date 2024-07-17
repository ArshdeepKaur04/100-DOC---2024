/*
Question "977. Squares of a Sorted Array" on leetcode - Did it myself :))
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in
non-decreasing order.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        for (int i:nums) {
            int temp = i*i;
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};