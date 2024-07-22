/*
Question "795. Number of Subarrays with Bounded Maximum" on leetcode
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays
such that the value of the maximum array element in that subarray is in the range [left, right].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start = -1, end = -1, result = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > right) {
                start = end = i;
                continue;
            }
            if (nums[i] >= left) {
                end = i;
            }
            result += end-start;
        }

        return result;
    }
};