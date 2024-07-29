/*
Question "Row with Max 1s" on Geeks for Geeks
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the
first row that has the most number of 1s. If no such row exists, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        int count = 0;
        vector<int> temp(rows, 0);
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(arr[i][j] == 1) {
                    count++;
                }
            }
            temp[i] = count;
            count = 0;
        }
        
        int ans = -1;
        int maxi = 0;
        for(int i=0; i<temp.size(); i++) {
            if (temp[i] > maxi) {
                maxi = temp[i];
                ans = i;
            }
        }
        return ans;
    }
};