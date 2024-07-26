/*
Question "509. Fibonacci Number" on leetcode
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number
is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n==0) {
            return 0;
        }
        if (n==1) {
            return 1;
        }
        int a=0, b=1, count=0, nextTerm;
        while(count <= n-2) {
            nextTerm = a+b;
            a = b;
            b = nextTerm;
            count++;
        }
        return nextTerm;
    }
};