/*
Question "773. Sliding Puzzle" on Leetcode
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it. The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]]. Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    string swap(string str, int i, int j) {
        std::swap(str[i], str[j]);
        return str;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        // swapping directions for all indexes in a string  
        vector<vector<int>> directions = { {1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4} };
        string target = "123450";
        string startState;
        // building the string from the board
        for (const auto& row : board) {
            for (int cell : row) {
                startState += to_string(cell);
            }
        }

        unordered_set<string> visited;
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;
        while (!queue.empty()) {
            int size = queue.size();
            while (size-- > 0) {
                string current = queue.front();
                queue.pop();

                if (current == target) return moves;

                int zeroPos = current.find('0');
                for (int newZeroPos : directions[zeroPos]) {
                    string nextState = swap(current, zeroPos, newZeroPos);

                    if (visited.count(nextState)) {
                        continue;
                    }
                    visited.insert(nextState);
                    queue.push(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};