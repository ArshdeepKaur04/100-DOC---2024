/*
Question "153. Find Minimum in Rotated Sorted Array" on Leetcode
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated
array nums of unique elements, return the minimum element of this array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, ans = INT_MAX;

        while(low <= high) {
            int mid = (low + high) / 2;
            //left part sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            //right part sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};