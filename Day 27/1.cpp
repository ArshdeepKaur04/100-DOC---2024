/*
Question "169. Majority Element" on leetcode
Given an array nums of size n, return the majority element. The majority element is the element that appears more
than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int n = floor(nums.size()/2);
        sort(nums.begin(), nums.end());
        return nums[n];
    }
};