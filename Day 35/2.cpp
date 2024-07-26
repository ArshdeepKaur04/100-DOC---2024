/*
Question "829. Consecutive Numbers Sum" on leetcode
Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int k=1; 2*n > k*(k-1); k++) {
            int numerator = n - (k*(k-1)/2);
            
            if (numerator % k == 0) {
                count++;
            }
        }

        return count;
    }
};