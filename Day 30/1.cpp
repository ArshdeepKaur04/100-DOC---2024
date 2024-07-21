/*
Question "628. Maximum Product of Three Numbers" on leetcode
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};