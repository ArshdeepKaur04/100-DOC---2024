/*
Question "954. Array of Doubled Pairs" on Leetcode
Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> count;
        
        // Count occurrences of each element
        for (int a : arr) {
            count[a]++;
        }
        
        // Iterate through the keys in ascending order
        for (auto& [x, freq] : count) {
            if (freq == 0) {
                continue;
            }
            
            int target;
            if (x < 0) {
                // For negative numbers, target is half of x
                target = x / 2;
            } else {
                // For positive numbers, target is twice x
                target = 2 * x;
            }
            
            // Check for invalid cases & return false
            if ((x < 0 && x % 2 != 0) || freq > count[target]) {
                return false;
            }
            
            count[target] -= freq;
        }
        
        return true;
    }
};