/*
Question "Minimum Swaps & K together" on Geeks for Geeks
Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number 
of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps 
required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minSwap(int arr[], int n, int k) {
        int nums = 0;
        for(int i=0; i<n; i++) {
            if (arr[i] <= k) {
                nums++;
            }
        }
        
        int curr_wndw =  0;
        for(int i=0; i<nums; i++) {
            if(arr[i] <= k) {
                curr_wndw++;
            }
        }
        
        int ans = nums - curr_wndw;
        for(int i=nums; i<n; i++) {
            if (arr[i] <= k) {
                curr_wndw++;
            }
            if (arr[i-nums] <= k) {
                curr_wndw--;
            }
            
            ans = min(ans, nums - curr_wndw);
        }
        
        return ans;
    }
};