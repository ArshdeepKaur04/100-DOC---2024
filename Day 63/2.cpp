/*
Question "134. Gas Station" on Leetcode
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i]. You have a 
car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th
station. You begin the journey with an empty tank at one of the gas stations. Given two integer arrays gas and cost,
return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if ( accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0) ) {
            return -1;
        }

        int total = 0;
        int res = 0;
        for(int i=0; i<gas.size(); i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                res = i+1;
            }
        }

        return res;
    }
};