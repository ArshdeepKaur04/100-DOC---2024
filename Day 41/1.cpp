/*
Question "680. Valid Palindrome II" on Leetcode
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;

        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        
        return true;
    }
};