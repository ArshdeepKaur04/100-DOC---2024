/*
Question "Remaining String" on GeeksForGeeks
Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that
remains after the character ch has appeared count number of times. Note:  Assume upper case and lower case alphabets
are different. ""(Empty string) should be returned if it is not possible, or the remaining substring is empty.
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    string printString(string s, char ch, int count) {
        string ans = "";
        int count2 = 0;
        int i = 0;
        int n = s.length();
        
        while(count2 != count && i < n) {
            if (s[i] == ch) {
                count2++;
            }
            i++;
        }
        
        if (i == n) {
            return ans;
        }
        else {
            for(int j=i; j<s.length(); j++) {
                ans += s[j];
            }
        }
        
        return ans;
    }
};