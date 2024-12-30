/*
Question "332. Reconstruct Itinerary" on Leetcode
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it. All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"]. You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    map<string, vector<string>> adj;
    vector<string> res;

    void dfs(string src) {
        // Traverse destinations in lexical order
        while (!adj[src].empty()) {
            string next = adj[src].back();
            adj[src].pop_back(); // Remove the edge
            dfs(next);
        }
        res.push_back(src); // Add to itinerary in reverse order
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build adjacency list
        for (auto ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        // Sort the destinations for lexical order
        for (auto& [src, destinations] : adj) {
            sort(destinations.rbegin(), destinations.rend());
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};