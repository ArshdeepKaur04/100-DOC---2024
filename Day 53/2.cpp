/*
Question "81. Search in Rotated Sorted Array II" on Leetcode
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values). Before being
passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting
array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, 
[0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4]. Given the array nums 
after the rotation and an integer target, return true if target is in nums, or false if it is not in nums. You must
decrease the overall operation steps as much as possible.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;;
            if(nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++, high--;
                continue;
            }

            //left sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            //right sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid + 1;
                }
            }
        }
        return false;
    }
};