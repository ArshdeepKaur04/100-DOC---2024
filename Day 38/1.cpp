/*
Question "Remove Duplicates" on Geeks for Geeks
Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first 
occurrence. Note: The original order of characters must be kept the same. 
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    string removeDups(string str) {
        int count[26] = {0};
        int i = 0;
        
        while (i < str.length()) {
            if (count[str[i] - 'a'] == 0) {
                count[str[i] - 'a']++;
                i++;
            } else {
                str.erase(str.begin() + i);
            }
        }
        
        return str;
    }
};