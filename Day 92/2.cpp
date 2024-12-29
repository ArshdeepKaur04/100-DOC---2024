/*
Question "684. Redundant Connection" on Leetcode
In this problem, a tree is an undirected graph that is connected and has no cycles. You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph. Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int node) {
        // recursively going to find the top parent
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionNodes(int i, int j) {
        int iRoot = find(i);
        int jRoot = find(j);

        if(iRoot != jRoot) {
            parent[jRoot] = iRoot;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);

        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }

        for(auto& edge: edges) {
            if(find(edge[0]) == find(edge[1])) {
                return edge;
            }
            unionNodes(edge[0], edge[1]);
        }

        return {};
    }
};