/*
Question "DFS of Graph" on GfG
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void dfs(int vertex, vector<int> graph[], bool visited[], vector<int> &ans) {
        if(visited[vertex]) {
            return;
        }
        
        visited[vertex] = true;
        ans.push_back(vertex);
        
        for(int child : graph[vertex]) {
            dfs(child, graph, visited, ans);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        bool visited[V]{false};
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, ans);
            }
        }
        return ans;
    }
};