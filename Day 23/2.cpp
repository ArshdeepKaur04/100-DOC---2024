/*
Question "50. Pow(x, n)" on leetcode

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
*/

//my code which is giving a integer overflow issue
/*
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        if (n > 0) {
            for (int i=0; i<n; i++) {
                ans = ans * x;
            }
        }
        else {
            x = 1/x;
            n = abs(n);
            for (int i=0; i<n; i++) {
                ans = ans * x;
            }
        }

        return ans;
    }
};
*/

//correct ans - solving it by recursion
/*
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == -1) {
            return 1 / x;
        }

        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        }
        else {
            if (n > 0) {
                return half * half * x;
            } 
            else {
                return half * half / x;
            }
        }
    }
};
*/