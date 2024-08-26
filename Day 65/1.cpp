/*
Question "853. Car Fleet" on Leetcode
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target. You are given 
two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and 
speed[i] is the speed of the ith car in miles per hour. A car cannot pass another car, but it can catch up and then
travel next to it at the speed of the slower car. A car fleet is a car or cars driving next to each other. The 
speed of the car fleet is the minimum speed of any car in the fleet. If a car catches up to a car fleet at the mile
target, it will still be considered as part of the car fleet. Return the number of car fleets that will arrive at 
the destination.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i=0; i<position.size(); ++i) {
            pair.push_back({position[i], speed[i]});
        }

        // Sort the pairs by position in descending order
        sort(pair.begin(), pair.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        stack<double> stacl;
        for (const auto& [p, s] : pair) {
            double time = static_cast<double>(target - p) / s;
            if (!stacl.empty() && time <= stacl.top()) {
                continue;
            }
            stacl.push(time);
        }

        return stacl.size();
    }
};