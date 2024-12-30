/*
Question "1857. Largest Color Value in a Directed Graph" on Leetcode
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1. You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj. A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path. Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int dfs(int node, const string& colors, unordered_map<int, vector<int>>& adj, vector<vector<int>>& count, unordered_set<int>& visit, unordered_set<int>& path) {
        if (path.count(node)) {
            return INT_MAX; // Cycle detected
        }
        if (visit.count(node)) {
            return 0; // Already visited
        }

        visit.insert(node);
        path.insert(node);

        int colorIndex = colors[node] - 'a';
        count[node][colorIndex] = 1;

        for (int nei : adj[node]) {
            if (dfs(nei, colors, adj, count, visit, path) == INT_MAX) {
                return INT_MAX; // Propagate cycle detection
            }
            for (int c=0; c<26; c++) {
                count[node][c] = max(count[node][c], count[nei][c] + (c == colorIndex ? 1 : 0));
            }
        }

        path.erase(node);
        return *max_element(count[node].begin(), count[node].end());
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> count(n, vector<int>(26, 0));
        unordered_set<int> visit, path;
        int res = 0;

        for (int i=0; i<n; i++) {
            res = max(dfs(i, colors, adj, count, visit, path), res);
            if (res == INT_MAX) {
                return -1; // Cycle detected
            }
        }

        return res;
    }
};