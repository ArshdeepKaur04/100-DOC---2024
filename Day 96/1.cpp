/*
Question "Maximum Bipartite Matching" on GfG
There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G where G(i,j) denotes ith applicant is interested in jth job. Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.
*/

#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    vector<int> matching;
    vector<int> vis;
    
    bool solve(int person, vector<vector<int>>&G) {
        for(int job=0; job<G[0].size(); job++) {
            if(G[person][job] && !vis[job]) {
                vis[job] = 1;
                if(matching[job] == -1 || solve(matching[job], G)) {
                    matching[job] = person;
                    return true;
                }
            }
        }
        
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&G){
	    int p = G.size();
	    int j = G[0].size();
	    int ans = 0;
	    matching = vector<int>(j, -1);
	    
	    for(int i=0; i<p; i++) {
	        vis = vector<int>(j, 0);
	        // checks if the job can be assigned or not
	        if(solve(i, G)) {
	            ans++;
	        }
	    }
	    
	    return ans;
	}
};