/*
Question "1283. Find the Smallest Divisor Given a Threshold" on Leetcode
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the
array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less
than or equal to threshold. Each result of the division is rounded to the nearest integer greater than or equal to
that element. (For example: 7/3 = 3 and 10/2 = 5).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findAnswer(vector<int> &nums, int val) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += ceil((double)(nums[i]) / (double)(val));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low <= high) {
            int mid = (low + high) / 2;
            int ans = findAnswer(nums, mid);
            if (ans <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }

        return low;
    }
};