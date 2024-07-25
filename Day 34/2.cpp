/*
Question "763. Partition Labels" on leetcode
You are given a string s. We want to partition the string into as many parts as possible so that each letter 
appears in at most one part. Note that the partition is done so that after concatenating all the parts in order, the
resultant string should be s. Return a list of integers representing the size of these parts.
*/

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;
        for (int i=0; i<s.length(); i++) {
            lastIndex[s[i]] = i;
        }

        vector<int> res;
        int size = 0, end = 0;
        for (int i=0; i<s.length(); i++) {
            size += 1;
            end = max(end, lastIndex[s[i]]);

            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        
        return res;
    }
};