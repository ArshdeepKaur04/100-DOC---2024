/*
Question "402. Remove K Digits" on Leetcode
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer
after removing k digits from num.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && k>0 && (st.top()-'0') > (num[i]-'0')) {
                st.pop();
                k = k-1;
            }
            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.empty()) {
            return "0";
        }

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        while(res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        if(res.empty()) {
            return "0";
        }
        else {
            return res;
        }
    }
};