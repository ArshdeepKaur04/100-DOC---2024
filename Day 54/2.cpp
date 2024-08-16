/*
Question "154. Find Minimum in Rotated Sorted Array II" on Leetcode
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated
array nums that may contain duplicates, return the minimum element of this array. You must decrease the overall 
operation steps as much as possible.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else if(nums[low] < nums[mid]) {
                high = mid - 1;
            }
            else {
                high--;
            }
        }
        return nums[low];
    }
};