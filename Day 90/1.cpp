/*
Question "Euler Circuit in an Undirected Graph" on GfG
Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian circuit else 0.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // degree of all vertices have to be even for eular circuit
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    for(int i=0; i<v; i++) {
	        if(adj[i].size() %2 != 0) {
	            return false;
	        }
	    }
	    
	    return true;
	}
};