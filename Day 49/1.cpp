/*
Question "Row with max 1s" on GfG
You are given a 2D array consisting of only 1's and 0's, where each row is sorted in non-decreasing order. You need
to find and return the index of the first row that has the most number of 1s. If no such row exists, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int i=0, j=arr[0].size()-1, ans=-1;
        
        while(i<arr.size() && j>=0) {
            if(!arr[i][j]) {
                i++;
            }
            else {
                ans = i;
                j--;
            }
        }
        
        return ans;
    }
};