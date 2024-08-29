/*
Question "834. Sum of Distances in Tree" on Leetcode
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges. You are given the
integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in
the tree. Return an array answer of length n where answer[i] is the sum of the distances between the ith node in 
the tree and all other nodes.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<int> adj[], int n, int node, int prev, vector<int> &height, vector<int> &subtree){
        subtree[node]++;
        for(auto &ele : adj[node]){
            if(ele != prev){
                height[ele] = 1+height[node];
                dfs(adj, n, ele, node, height, subtree);
                subtree[node] += subtree[ele];
            }
        }
    }
    
    void rec(vector<int> adj[], int n, int node, int prev, vector<int> &subtree, vector<int> &dp){
        for(auto &ele : adj[node]){
            if(ele != prev){
                dp[ele] = dp[node] - subtree[ele] + (n-subtree[ele]);
                rec(adj, n, ele, node, subtree, dp);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &ele : edges){
            int u = ele[0], v = ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> height(n, 0), subtree(n, 0); // distance from 0 to all other nodes;
        vector<int> dp(n, 0); // dp[i] = sum of distances from node i to all other nodes;
        dfs(adj, n, 0, -1, height,subtree);
        for(int i=0; i<n; i++) dp[0] += height[i];
        rec(adj, n, 0, -1, subtree, dp);
        return dp;
    }
};