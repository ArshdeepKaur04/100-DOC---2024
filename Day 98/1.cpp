/*
Question "781. Rabbits in Forest" on Leetcode
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit. Given the array answers, return the minimum number of rabbits that could be in the forest.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> countMap;
        for (int answer : answers) {
            countMap[answer]++;
        }

        int ans = 0;
        for (auto& entry : countMap) {
            int key = entry.first;
            int value = entry.second;
            int groupSize = key + 1;
            int groups = ceil(static_cast<double>(value) / groupSize);
            ans += groups * groupSize;
        }

        return ans;
    }
};