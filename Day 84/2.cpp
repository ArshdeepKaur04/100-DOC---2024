/*
Question "399. Evaluate Division" on Leetcode
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable. You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?. Return the answers to all queries. If a single answer cannot be determined, return -1.0.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>&adj, string src, string dst, unordered_set<string> &visited, 
    double product, double &ans) {
        // if source already visited
        if(visited.find(src) != visited.end()) {
            return;
        }

        visited.insert(src); // mark visited

        if (src == dst) {
            ans = product;
            return;
        }

        for(auto &p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(adj, v, dst, visited, product*val, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Making the graph
        for(int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0/val});
        }

        vector<double> result;
        for(auto &query : queries) {
            string src = query[0];
            string dst = query[1];
            double ans = -1.0;
            double product = 1.0;

            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                dfs(adj, src, dst, visited, product, ans);
            }

            result.push_back(ans);
        }

        return result;
    }
};