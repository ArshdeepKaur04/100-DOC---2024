/*
Question "1190. Reverse Substrings Between Each Pair of Parentheses" on leetcode
You are given a string s that consists of lower case English letters and brackets. Reverse the strings in each pair
of matching parentheses, starting from the innermost one. Your result should not contain any brackets.
*/

/*
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    string reverseParentheses(string s) {
        deque<int> ind_stack;
        vector<char> res;

        for (char char_s : s) {
            if (char_s == '(') {
                ind_stack.push_back(res.size());
            } else if (char_s == ')') {
                int start_ind = ind_stack.back();
                ind_stack.pop_back();
                reverse(res.begin() + start_ind, res.end());
            } else {
                res.push_back(char_s);
            }
        }

        return string(res.begin(), res.end());
    }
};
*/