/*
Question "Smallest Number" on GeeksForGeeks
Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the 
number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible
then return -1.
*/

#include <iostream>
using namespace std;

class Solution {
  public:
    string smallestNumber(int s, int d) {
        string ans = "";
        int i = 1;
        int num = 0;
        
        while(i <= d) {
            if(s-(d-i)*9 <= 0) {
                num = 0;
            }
            else {
                num = s-(d-i)*9;
            }
            
            if (num == 0 && i == 1) {
                num = 1;
            }
            
            if (num > 9) {
                return "-1";
            }
            
            ans += (num + '0');
            i++;
            s -= num;
        }
        
        return ans;
    }
};