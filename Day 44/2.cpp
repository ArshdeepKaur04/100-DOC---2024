/*
Question "1031. Maximum Sum of Two Non-Overlapping Subarrays" on Leetcode
Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two 
non-overlapping subarrays with lengths firstLen and secondLen. The array with length firstLen could occur before
or after the array with length secondLen, but they have to be non-overlapping. A subarray is a contiguous part of 
an array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> arr(n + 1, 0);

        for(int i=0; i<n; i++){
            arr[i+1] = nums[i] + arr[i];
        }

        int sum=0;

        for(int i=0; i<=n-firstLen-secondLen; i++){
            int firstsum = arr[i+firstLen] - arr[i];
            for(int j=i+firstLen; j<=n-secondLen; j++){
                int secondsum = arr[j+secondLen] - arr[j];
                sum = max(sum,firstsum+secondsum);
            }
        }

        for(int i=0; i<=n-firstLen-secondLen; i++){
            int secondsum = arr[i+secondLen] - arr[i];
            for(int j=i+secondLen; j<=n-firstLen; j++){
                int firstsum = arr[j+firstLen] - arr[j];
                sum = max(sum,firstsum+secondsum);
            }
        }
        
        return sum;
    }
};