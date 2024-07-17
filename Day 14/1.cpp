/*
Question:
"Least Moves" on HackerRank

In a school assembly, your class students are standing in random order. Now you need to arrange them in non 
decreasing order of their height. In one move you can remove all the students who have their height less than the 
student in the front of them (i.e if heights are given as an array, the student removed in a move will be ith 
student where height[i-1] > height[i]). So more formally you are given an array height[] of size n and your task is
to return the minimum number of moves after which heights becomes non decreasing.
*/

#include <iostream>
#include <vector>
using namespace std;

int minMovesToNonDecreasingOrder(vector<int> &height) {
    int n = height.size();
    int moves = 0;

    while (true) {
        bool removed = false;
        vector<int> newHeights;
        newHeights.push_back(height[0]);

        for (int i = 1; i < n; ++i) {
            if (height[i] >= height[i - 1]) {
                newHeights.push_back(height[i]);
            }
            else {
                removed = true;
            }
        }

        if (!removed)
            break;

        height = newHeights;
        n = height.size();
        ++moves;
    }

    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    cout <<  minMovesToNonDecreasingOrder(height) << endl;

    return 0;
}