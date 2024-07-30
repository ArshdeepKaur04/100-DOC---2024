/*
Question "48. Rotate Image" on Leetcode
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise). You have to
rotate the image in-place, which means you have to modify the input 2D matrix directly.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size() - 1;

        while(l < r) {
            for(int i=0; i<(r-l); i++) {
                int top = l;
                int bottom = r;

                int topLeft = matrix[top][l+i];
                matrix[top][l+i] = matrix[bottom-i][l];
                matrix[bottom-i][l] = matrix[bottom][r-i];
                matrix[bottom][r-i] = matrix[top+i][r];
                matrix[top+i][r] = topLeft;
            }
            l++;
            r--;
        }
    }
};