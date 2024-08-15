/*
Question "Sorted Matrix" on GfG
Given an NxN matrix Mat. Sort all elements of the matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // Step 1: Flatten the matrix into a 1D array
        vector<int> temp(N * N);
        int index = 0;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                temp[index++] = Mat[i][j];
            }
        }
    
        // Step 2: Sort the 1D array
        sort(temp.begin(), temp.end());
    
        // Step 3: Reconstruct the sorted matrix
        index = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                Mat[i][j] = temp[index++];
            }
        }
        
        return Mat;
    }
};