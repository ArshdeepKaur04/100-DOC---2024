/*
Question "Minimize the Heights II" on GfG
Given an array arr[] denoting heights of N towers and a positive integer K. For each tower, you must perform exactly
one of the following operations exactly once: Increase the height of the tower by K or decrease the height of the
tower by K. Find out the minimum possible difference between the height of the shortest and tallest towers after 
you have modified each tower. It is compulsory to increase or decrease the height by K for each tower. 
After the operation, the resultant array should not contain any negative integers.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int minEle, maxEle;
        int result = arr[n-1] - arr[0];
        
        for(int i=1; i<=n-1; i++) {
            if (arr[i] >= k) {
                maxEle = max(arr[i-1] + k, arr[n-1]-k);
                minEle = min(arr[0]+k, arr[i]-k);
                
                result = min(result, maxEle-minEle);
            }
        }
        
        return result;
    }
};