/*
Question "905. Sort Array by Parity" on leetcode
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd 
integers. Return any array that satisfies this condition.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size()-1;

        while(start < end) {
            while (start < end && nums[start] % 2 == 0 ) {
                start++;
            }
            while(start < end && nums[end] % 2 != 0) {
                end--;
            }
            if (start < end) {
                swap(nums[start], nums[end]);
            }
        }

        return nums;
    }
};