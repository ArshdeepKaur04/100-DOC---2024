/*
Question "Maximum Product Subset of an Array" on GeeksForGeeks
Given an array arr. The task is to find and return the maximum product possible with the subset of elements present
in the array.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        if (arr.size() == 1) {
            return arr[0];
        }
        
        long long int pos=1, neg=1, negLar=INT_MIN, mod = 1e9+7, c1=0, c2=0;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]<0) {
                neg = (neg*(long long int)arr[i])%mod;
                negLar = max((long long int)arr[i], negLar);
                c1++;
            }
            if (arr[i]>0) {
                pos = (pos*(long long int)arr[i])%mod;
                c2++;
            }
        }
        
        if (c1 <= 1 && c2 == 0) {
            return 0;
        }
        if (neg < 0) {
            neg = neg/negLar;
        }
        
        return (pos*neg)%mod;
    }
};