/*
Question "685. Redundant Connection II" on Leetcode
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents. The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi. Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.
*/

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findParent(int n) {
        int p = parent[n];
        while(p != parent[p]) {
            p = findParent(parent[parent[p]]);
        }
        return p;
    }

    bool unionize(int n1, int n2) {
        int p1 = findParent(n1);
        int p2 = findParent(n2);
        
        if(p1 == p2) {
            return true;
        }

        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else if(rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else {
            parent[p2] = p1;
            rank[p1]+=1;
        }

        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n, -1);
        int a = -1, b = -1;
        for(int i=0; i<n; i++) {
            if(indegree[edges[i][1]-1] != -1) {
                a = i;
                b = indegree[edges[i][1]-1];
            }
            indegree[edges[i][1]-1] = i;
        }

        UnionFind* u = new UnionFind(n);
        for(int i=0; i<n; i++) {
            if (a == i) {
                continue;
            }
            if (u -> unionize(edges[i][0], edges[i][1])) {
                if(a == -1) {
                    return edges[i];
                } else {
                    return edges[b];
                }
            }
        }

        return edges[a];
    }
};