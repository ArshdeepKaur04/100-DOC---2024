/*
Question "Traverse All Edges And Vertices" on GfG
You are presented with an undirected connected graph consisting of n vertices and connections between them represented by an adjacency matrix. Your objective is to determine whether it is possible to start traversing from a node, x, and return to it after traversing all the vertices at least once, using each edge exactly once.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isConnected(const vector<vector<int>>& graph, int n) {
        vector<bool> visited(n, false);
        queue<int> q;
    
        // Find the first node with edges to start BFS
        int startNode = -1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (graph[i][j] > 0) {
                    startNode = i;
                    break;
                }
            }
            if (startNode != -1) {
                break;
            }
        }
    
        if (startNode == -1) {
            return false; // No edges in the graph
        }
    
        q.push(startNode);
        visited[startNode] = true;
    
        while (!q.empty()) {
            int node = q.front();
            q.pop();
    
            for (int neighbor=0; neighbor<n; neighbor++) {
                if (graph[node][neighbor] > 0 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    
        // Check if all nodes with edges are visited
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (graph[i][j] > 0 && !visited[i]) {
                    return false;
                }
            }
        }
        return true;
    }

	int isPossible(vector<vector<int>>paths){
	    int n = paths.size();

        // Check if all vertices have even degrees
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                degree += paths[i][j];
            }
            if (degree % 2 != 0) {
                return 0; // Odd degree found, thus no chance of Eulerian Circuit
            }
        }
    
        // Check if the graph is connected
        if(isConnected(paths, n)) {
            return 1;
        }else {
            return 0;
        }
	}
};