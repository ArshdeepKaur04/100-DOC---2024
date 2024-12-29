/*
Question "Eulerian Path in an Undirected Graph" on GfG
Given an adjacency matrix representation of an unweighted undirected graph named graph, which has N vertices. You have to find out if there is an eulerian path present in the graph or not.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int eulerPath(int n, vector<vector<int>> graph){
        int c = 0;
        for(int i=0; i<n; i++) {
            int cn = 0;
            for(int j=0; j<n; j++) {
                if(graph[i][j]) {
                    cn++;
                }
            }
            if(cn%2) {
                c++;
            }
        }
        
        if (c==0 || c==2) {
            return 1;
        }
        
        return 0;
    }
};