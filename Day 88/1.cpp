/*
Question "1034. Coloring A Border" on Leetcode
You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location. Two squares are called adjacent if they are next to each other in any of the 4 directions. Two squares belong to the same connected component if they have the same color and they are adjacent. The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column). You should color the border of the connected component that contains the square grid[row][col] with color. Return the final grid.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> v;

    void dfs(vector<vector<int>>& grid, int row, int col, int color, int ocolor) {
        int n = grid.size();
        int m = grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!=ocolor) {
            return;
        }
        grid[row][col] = -color;

        dfs(grid, row-1, col, color, ocolor);
        dfs(grid, row, col+1, color, ocolor);
        dfs(grid, row+1, col, color, ocolor);
        dfs(grid, row, col-1, color, ocolor);

        if(row>0 && col>0 && row<n-1 && col<m-1 && grid[row-1][col] == -color && grid[row][col+1] == -color && grid[row+1][col] == -color && grid[row][col-1] == -color) {
            v.push_back({row, col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int ocolor = grid[row][col];

        if(ocolor == color) {
            return grid;
        }

        dfs(grid, row, col, color, ocolor);

        for(auto p:v) {
            int r = p.first;
            int c = p.second;
            grid[r][c] = ocolor;
        }

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] < 0) {
                    grid[i][j] *= -1;
                }
            }
        }

        return grid;
    }
};