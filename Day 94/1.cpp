/*
Question "924. Minimize Malware Spread" on Leetcode
You are given a network of n nodes represented as an n x n adjacency matrix graph, where the ith node is directly connected to the jth node if graph[i][j] == 1. Some nodes initial are initially infected by malware. Whenever two nodes are directly connected, and at least one of those two nodes is infected by malware, both nodes will be infected by malware. This spread of malware will continue until no more nodes can be infected in this manner. Suppose M(initial) is the final number of nodes infected with malware in the entire network after the spread of malware stops. We will remove exactly one node from initial. Return the node that, if removed, would minimize M(initial). If multiple nodes could be removed to minimize M(initial), return such a node with the smallest index. Note that if a node was removed from the initial list of infected nodes, it might still be infected later due to the malware spread.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cnt; //group size

    void dfs(vector<vector<int>>& adj, int curr, vector<int>& visited, int assgn) {
        visited[curr] = assgn;
        cnt++;

        for(auto el: adj[curr]) {
            if(visited[el] == -1) {
                dfs(adj, el, visited, assgn);
            }
        }
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int nodes = graph.size();
        vector<vector<int>> adj(nodes+1);

        // building the adjacency list  
        for(int i=0; i<nodes; i++) {
            for(int j=0; j<nodes; j++) {
                if(graph[i][j] == 1) {
                    adj[i+1].push_back(j+1);
                }
            }
        }

        vector<int> visited(nodes+1, -1);
        map<int, pair<int, int>> assign;
        int assgn = 1;

        for(auto el: initial) {
            // no color has been assigned till now
            if(visited[el+1] == -1) {
                this->cnt = 0;
                dfs(adj, el+1, visited, assgn);
                assign[assgn].first = cnt;
                assign[assgn].second += 1;
            } else {
                assign[visited[el+1]].second += 1;
            }
            assgn++;
        }

        sort(initial.begin(), initial.end());
        int ans = -1;
        int finalSaves = -1; //number of nodes getting saved

        for(auto el:initial) {
            int getAssignmentNumber = visited[el+1];
            int totalInfected = assign[getAssignmentNumber].second;
            int groupSize = assign[getAssignmentNumber].first;
            if(totalInfected == 1) {
                if(groupSize > finalSaves) {
                    ans = el+1;
                    finalSaves = groupSize;
                }
            }
        }

        // if all the groups have more than 1 member infected
        if(ans == -1) {
            return initial[0];
        }

        return ans-1;
    }
};