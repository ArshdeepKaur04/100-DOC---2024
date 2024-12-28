/*
Question "934. Shortest Bridge" on Leetcode
You are given an n x n binary matrix grid where 1 represents land and 0 represents water. An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid. You may change 0's to 1's to connect the two islands to form one island. Return the smallest number of 0's you must flip to connect the two islands.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        set<pair<int, int>> visit;

        auto invalid = [&](int r, int c) {
            return r < 0 || c < 0 || r >= N || c >= N;
        };

        // Perform DFS to find the first island and add its coordinates to `visit`
        function<void(int, int)> dfs = [&](int r, int c) {
            if (invalid(r, c) || grid[r][c] == 0 || visit.count({r, c}))
                return;
            visit.insert({r, c});
            for (auto [dr, dc] : directions) {
                dfs(r + dr, c + dc);
            }
        };

        // Perform BFS to find the shortest path to the second island
        auto bfs = [&]() {
            queue<pair<int, int>> q;
            for (auto& cell : visit) {
                q.push(cell);
            }
            int res = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    auto [r, c] = q.front();
                    q.pop();
                    for (auto [dr, dc] : directions) {
                        int curR = r + dr, curC = c + dc;
                        if (invalid(curR, curC) || visit.count({curR, curC}))
                            continue;
                        if (grid[curR][curC] == 1)
                            return res;
                        q.push({curR, curC});
                        visit.insert({curR, curC});
                    }
                }
                res++;
            }
            return res;
        };

        // Locate the first island
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    dfs(r, c);
                    return bfs();
                }
            }
        }
        
        return -1; // Fallback in case no islands are found
    }
};