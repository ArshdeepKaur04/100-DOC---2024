/*
Question "1203. Sort Items by Groups Respecting Dependencies" on Leetcode
There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it. Return a sorted list of the items such that:
- The items that belong to the same group are next to each other in the sorted list.
- There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
Return any solution if there is more than one solution and return an empty list if there is no solution.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& graph, vector<int> &indegree) {
        vector<int> visited;
        stack<int> stk;
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) {
                stk.push(i);
            }
        }

        while(!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            visited.push_back(curr);

            for(int n: graph[curr]) {
                indegree[n]--;
                if(indegree[n] == 0) {
                    stk.push(n);
                }
            }
        }

        if(visited.size() == graph.size()) {
            return visited;
        } else {
            return vector<int>();
        }
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        // assigning group numbers to items with no groups
        for(int i=0; i<n; i++) {
            if(group[i] == -1) {
                group[i] = groupId++;
            }
        }

        unordered_map<int, vector<int>> itemGraph;
        // initializes each item with a key of an empty array to be used in Topological Sort
        vector<int> itemIndegree(n, 0);
        for(int i=0; i<n; i++) {
            itemGraph[i] = vector<int>();
        }

        unordered_map<int, vector<int>> groupGraph;
        // initializes each group with a key of an empty array to be used in Topological Sort
        vector<int> groupIndegree(groupId, 0);
        for(int i=0; i<groupId; i++) {
            groupGraph[i] = vector<int>();
        }

        for(int i=0; i<n; i++) {
            for(int prev: beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if(group[i] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }

        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }
       
        unordered_map<int, vector<int>> orderedGroups;
        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }
        
        vector<int> answerList;
        for (int groupIndex : groupOrder) {
            answerList.insert(answerList.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
        }
        
        return answerList;
    }
};