/*
Question "4. Median of Two Sorted Arrays" on Leetcode
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0;
        int j = 0;
        int n = (n1 + n2);
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;
        while(i<n1 && j<n2) {
            if(a[i] < b[j]) {
                if(cnt == ind1) {
                    ind1el = a[i];
                }
                if(cnt == ind2) {
                    ind2el = a[i];
                }
                cnt++;
                i++;
            }
            else {
                if(cnt == ind1) {
                    ind1el = b[j];
                }
                if(cnt == ind2) {
                    ind2el = b[j];
                }
                cnt++;
                j++;
            }
        }

        while(i<n1) {
            if(cnt == ind1) {
                    ind1el = a[i];
                }
                if(cnt == ind2) {
                    ind2el = a[i];
                }
                cnt++;
                i++;
        }

        while(j<n2) {
            if(cnt == ind1) {
                    ind1el = b[j];
                }
                if(cnt == ind2) {
                    ind2el = b[j];
                }
                cnt++;
                j++;
        }

        if(n % 2 == 1) {
            return ind2el;
        }

        return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};