/*
Question "803. Bricks Falling When Hit" on Leetcode
You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if: 
- It is directly connected to the top of the grid, or
- At least one other brick in its four adjacent cells is stable.
You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks). Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> DIR = {-1, 0, 1, 0, -1};
    vector<int> parents, sizes;
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int R = grid.size(), C = grid[0].size();
        parents.resize(R * C + 1);
        sizes.resize(R * C + 1, 1);
        for (int i = 0; i < parents.size(); i++) {
            parents[i] = i;
        }

        vector<int> originals(hits.size());
        for (int i = 0; i < hits.size(); i++) {
            originals[i] = grid[hits[i][0]][hits[i][1]];
            grid[hits[i][0]][hits[i][1]] = 0;
        }

        // Initial union
        int SKY = R * C;
        for (int c = 0; c < C; c++) {
            if (grid[0][c] == 1) {
                unionSet(c, SKY);
            }
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 0) continue;
                for (int i = 0; i < 4; i++) {
                    int nr = r + DIR[i], nc = c + DIR[i + 1];
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == 0) {
                        continue;
                    }
                    unionSet(r * C + c, nr * C + nc);
                }
            }
        }

        // Reverse the hits
        vector<int> res(hits.size());
        for (int j = hits.size() - 1; j >= 0; j--) {
            if (originals[j] == 0) continue;

            int r = hits[j][0], c = hits[j][1];
            int beforeSkySize = sizes[find(SKY)];
            if (r == 0) {
                unionSet(r * C + c, SKY);
            }

            // Try union with 4 directions
            for (int i = 0; i < 4; i++) {
                int nr = r + DIR[i], nc = c + DIR[i + 1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == 0) {
                    continue;
                }
                unionSet(r * C + c, nr * C + nc);
            }

            int myParent = find(r * C + c);
            if (myParent == find(SKY)) {
                res[j] = sizes[myParent] - beforeSkySize - 1;
            }

            grid[r][c] = 1; // Undo the set to 0
        }

        return res;
    }

private:
    int find(int i) {
        if (parents[i] == i) {
            return i;
        }
        return parents[i] = find(parents[i]);
    }

    void unionSet(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return;
        if (i > j) {
            parents[j] = i;
            sizes[i] += sizes[j];
        } else {
            parents[i] = j;
            sizes[j] += sizes[i];
        }
    }
};