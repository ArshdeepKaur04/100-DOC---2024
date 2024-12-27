/*
Question "815. Bus Routes" on Leetcode
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats  forever. You will start at the bus stop source, and you want to go to the bus stop target. You can travel between bus stops by buses only. Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> adj; //key = stops & value = indices
        for(int route=0; route<routes.size(); route++) {
            for(auto &stop: routes[route]) {
                adj[stop].push_back(route);
            }
        }

        queue<int> que;
        vector<bool> visited(501, false);
        for(auto &route : adj[source]) {
            que.push(route);
            visited[route] = true;
        }

        int busCount = 1;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int route = que.front();
                que.pop();

                for(auto &stop : routes[route]) {
                    if (stop == target) {
                        return busCount;
                    }
                    
                    for(auto &nextRoute : adj[stop]) {
                        if(visited[nextRoute] == false) {
                            visited[nextRoute] = true;
                            que.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }

        return -1;
    }
};