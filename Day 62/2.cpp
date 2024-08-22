/*
Question "921. Minimum Add to Make Parentheses Valid" on Leetcode
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string. 
Return the minimum number of moves required to make s valid.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, bal = 0;

        for(int i=0; i<s.length(); i++) {
            //an opening bracket
            if (s[i] == '(') {
                bal++;
            }
            //unbalanced closing brakcet 
            else if (bal <= 0) {
                res++;
            }
            //balanced closing bracket
            else {
                bal--;
            }
        }

        return res + bal;
    }
};