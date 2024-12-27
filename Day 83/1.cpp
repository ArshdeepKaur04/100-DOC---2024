/*
Question "785. Is Graph Bipartite?" on Leetcode
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B. Return true if and only if it is bipartite.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>&colors, int color, int node) {
        if(colors[node] != 0) {
            return colors[node] == color;
        }
        colors[node] = color;
        for(int child : adj[node]) {
            if(dfs(adj, colors, -1*color, child) == false) {
                return false;
            }
        }

        return true;
    } 
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);

        for(int i=0; i<n; i++) {
            // 1 is red color & -1 is blue color
            if(colors[i]==0 && dfs(graph, colors, 1, i) == false) {
                return false;
            }
        }

        return true;
    }
};