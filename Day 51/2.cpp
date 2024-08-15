/*
Question "410. Split Array Largest Sum" on Leetcode
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of 
any subarray is minimized. Return the minimized largest sum of the split.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int subarrays = 1;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if (ans + nums[i] <= k) {
                ans += nums[i];
            }
            else {
                subarrays += 1;
                ans = nums[i];
            }
        }
        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high) {
            int mid = (low + high) / 2;
            int subarrays = countSubarrays(nums, mid);
            if (subarrays > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};