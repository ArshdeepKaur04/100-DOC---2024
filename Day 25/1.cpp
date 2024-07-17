/*
Question "27. Remove Element" on leetcode
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the 
elements may be changed. Then return the number of elements in nums which are not equal to val.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0, end=nums.size()-1;
        
        while (start <= end) {
            while (start <= end && nums[start] != val) {
                start++;
            }
            while (start <= end && nums[end] == val) {
                end--;
            }
            if (start < end) {
                swap(nums[start++], nums[end--]);
            }
        }

        return start;
    }
};