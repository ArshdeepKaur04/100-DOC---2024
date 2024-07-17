/*
Question:
Given a grid with blocked and unblocked cells, find the minimum number of moves required to reach from the start to
the goal.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y, int rows, int cols, vector<vector<char>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == '.';
}

int minMoves(vector<vector<char>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    if (rows == 0) return -1;
    int cols = grid[0].size();

    if (start == goal) return 0; // If start is the same as goal, return 0 moves

    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = 'X';
    int moves = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            pair<int, int> current = q.front(); q.pop();
            int x = current.first, y = current.second;
            if (x == goal.first && y == goal.second) {
                return moves;
            }

            for (const pair<int, int>& dir : directions) {
                int newX = x + dir.first, newY = y + dir.second;
                if (isValid(newX, newY, rows, cols, grid)) {
                    q.push({newX, newY});
                    grid[newX][newY] = 'X';
                }
            }
        }
        ++moves;
    }

    return -1; // Goal not reachable
}

int main() {
    vector<vector<char>> grid = {
        {'.', '.', '.'},
        {'.', 'X', '.'},
        {'.', '.', '.'}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {2, 2};

    int result = minMoves(grid, start, goal);

    if (result != -1) {
        cout << "Minimum moves: " << result << endl;
    } else {
        cout << "No path found from start to goal." << endl;
    }

    return 0;
}