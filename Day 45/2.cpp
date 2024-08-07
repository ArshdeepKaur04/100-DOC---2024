/*
Question "899. Orderly Queue" on Leetcode
You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end
of the string. Return the lexicographically smallest string you could have after applying the mentioned step any 
number of moves.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string s_min = s;

        for(int i=0; i<s.length(); ++i) {
            s = s.substr(1) + s[0];
            s_min = min(s_min, s);
        }

        return s_min;
    }
};