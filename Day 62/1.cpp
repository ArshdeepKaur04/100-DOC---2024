/*
Question "735. Asteroid Collision" on Leetcode
We are given an array asteroids of integers representing asteroids in a row. For each asteroid, the absolute value
represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each
asteroid moves at the same speed. Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same
direction will never meet.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            }
            else {
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() == abs(asteroids[i])) {
                    ans.pop_back();
                }
                else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                }
            }
        }

        return ans;
    }
};