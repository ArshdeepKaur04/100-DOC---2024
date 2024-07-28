/*
Question "K-Pangrams" on Geeks for Geeks
Given a string str and an integer k, return true if the string can be changed into a pangram after at most k 
operations, else return false. A single operation consists of swapping an existing alphabetic character with any
other lowercase alphabetic character.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool kPangram(string str, int k) {
        int count[26] = {0};
        int n = str.length();
        
        for (int i = 0; i < n; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                count[str[i] - 'a']++;
            } else if (str[i] >= 'A' && str[i] <= 'Z') {
                count[str[i] - 'A']++;
            }
        }
        
        int missingLetters = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) {
                missingLetters++;
            }
        }
        
        return missingLetters <= k;
    }
};