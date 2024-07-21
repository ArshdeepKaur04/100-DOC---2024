/*
Question "724. Largest Number At Least Twice of Others" on leetcode
You are given an integer array nums where the largest integer is unique. Determine whether the largest element in
the array is at least twice as much as every other number in the array. If it is, return the index of the largest 
element, or return -1 otherwise.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = 0;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                ans = i;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == maxi) {
                continue;
            }
            else {
                if (maxi >= 2*nums[i]) {
                    continue;
                }
                else {
                    return -1;
                }
            }
        }

        return ans;
    }
};