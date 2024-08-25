/*
Question "316. Remove Duplicate Letters" on Leetcode
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your
result is  the smallest in lexicographical order among all possible results.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        vector<bool> vis(26);
        string ans = "";
        int n = s.size();

        for(int i=0; i<n; i++) {
            last[s[i] - 'a'] = i;
        }

        for(int i=0; i<n; i++) {
            if(vis[s[i] - 'a']) {
                continue;
            }

            while(!ans.empty() && ans.back() > s[i] && last[ans.back()-'a'] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};