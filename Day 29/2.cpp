/*
Question "768. Max Chunks To Make Sorted II" on leetcode
You are given an integer array arr. We split arr into some number of chunks (i.e., partitions), and individually
sort each chunk. After concatenating them, the result should equal the sorted array. Return the largest number of 
chunks we can make to sort the array.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int rmin[n+1];

        rmin[n] = INT_MAX;
        for (int i=n-1; i>=0; i--) {
            rmin[i] = min(rmin[i+1], arr[i]);
        }

        int lmax = INT_MIN;
        int cnt = 0;

        for (int i=0; i<n; i++) {
            lmax = max(lmax, arr[i]);
            if (lmax <= rmin[i+1]) {
                cnt++;
            }
        }

        return cnt;
    }
};