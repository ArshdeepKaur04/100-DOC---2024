/*
Question "871. Minimum Number of Refueling Stops" on Leetcode
A car travels from a starting position to a destination which is target miles east of the starting position. There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas. The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car. Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq; // Max-heap to store fuel amounts.

        int refill = 0, i = 0;
        int distance = startFuel;

        while (distance < target) {
            // Add all stations within the current range to the priority queue.
            while (i < n && distance >= stations[i][0]) {
                pq.push(stations[i][1]);
                i++;
            }

            // If no stations are left to refuel and we can't reach the target.
            if (pq.empty()) return -1;

            // Refuel with the maximum fuel from the heap.
            distance += pq.top();
            pq.pop();
            refill++;
        }

        return refill;
    }
};