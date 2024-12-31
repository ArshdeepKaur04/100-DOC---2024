/*
Question "914. X of a Kind in a Deck of Cards" on Leetcode
You are given an integer array deck where deck[i] represents the number written on the ith card. Partition the cards into one or more groups such that:
- Each group has exactly x cards where x > 1, and
- All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // Count the frequency of each number
        unordered_map<int, int> count;
        for (int card : deck) {
            count[card]++;
        }

        // Compute the GCD of all frequencies
        int gcd = 0;
        for (auto& [card, freq] : count) {
            if (gcd == 0) {
                gcd = freq;
            } else {
                gcd = std::gcd(gcd, freq);
            }
        }

        // Check if the GCD is at least 2
        return gcd >= 2;
    }
};