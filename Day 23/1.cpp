/*
Question "8. String to Integer (atoi)" on leetcode

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer. Return the integer as
the final result.
*/

//my approach
/*
int myAtoi(string s) {
    string ans;
    if (s[0] == '-') {
        ans.push_back('-');
    }
    for (int i=1; i<s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans.push_back(s[i]);
        }
        else {
            break;
        }
    }
    int finalAns = int(ans);
    return finalAns;
}
*/

//correct ans
/*
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long ans = 0;

        //ignoring the leading whitespaces
        while(i<s.length() && s[i]==' ') {
            i++;
        }
    
        //checking the sign
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+') {
            i++;
        }
        
        while(i < s.length()) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans = ans*10 + (s[i]-'0');
                //checking overflow conditions
                if(ans > INT_MAX && sign == -1) {
                    return INT_MIN;
                }
                else if(ans > INT_MAX && sign == 1) {
                    return INT_MAX;
                }
                i++;
            }
            else
                return ans*sign;
        }
        return (ans*sign);
    }
};
*/