/*
Question "9. Palindrome Number" on leetcode
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int i = 0, j = str.length()-1;

        while(i <= j) {
            if (str[i] == str[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};