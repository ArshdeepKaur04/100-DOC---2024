/*
Question "925. Long Pressed Name" on Leetcode
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long 
pressed, and the character will be typed 1 or more times. You examine the typed characters of the keyboard. Return
True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1 = name.length();
        int n2 = typed.length();
        int idx1 = 0;
        int idx2 = 0;

        while(idx1<n1 && idx2<n2) {
            if(name[idx1] == typed[idx2]) {
                idx1++;
                idx2++;
                continue;
            }

            if(idx1>0 && name[idx1-1] == typed[idx2]) {
                idx2++;
            }
            else {
                return false;
            }
        }

        if(idx1 < n1) {
            return false;
        }

        while(idx2 < n2) {
            if(typed[idx2] != name[n1-1]) {
                return false;
            }
            idx2++;
        }

        return true;
    }
};