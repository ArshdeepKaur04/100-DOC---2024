/*
Question "1007. Minimum Dominos Rotations For Equal Row" on leetcode
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a
tile with two numbers from 1 to 6 - one on each half of the tile.) We may rotate the ith domino, so that tops[i] 
and bottoms[i] swap values. Return the minimum number of rotations so that all the values in tops are the same, or 
all the values in bottoms are the same. If it cannot be done, return -1.
*/

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int dp1[100001][8];
    int dp2[100001][8];
    int make_top_equal(int i, int last, vector<int>& tops, vector<int>& bottom){
        if(i==tops.size()) {
            return 0;
        }

        if(i>0 and tops[i]!=last and bottom[i]!=last) {
            return 1e9;
        }

        if(dp1[i][last+1] != -1) {
            return dp1[i][last+1];
        }

        int op1 = INT_MAX, op2 = INT_MAX;

        if(last == -1 || bottom[i] == last) {
            op1 = 1 + make_top_equal(i+1,bottom[i],tops,bottom);
        }
        
        if(last == -1 || tops[i] == last) {
            op2 = make_top_equal(i+1,tops[i],tops,bottom);
        } 
        
        return dp1[i][last+1] = min(op1,op2);
    }

    int make_bottom_equal(int i, int last, vector<int>& tops, vector<int>& bottom){
        if(i==tops.size()) {
            return 0;
        }
        
        if(i>0 and tops[i]!=last and bottom[i]!=last) {
            return 1e9;
        }

        if(dp2[i][last+1] != -1) {
            return dp2[i][last+1];
        }
        
        int op1 = INT_MAX, op2 = INT_MAX;
        
        if(last == -1 || tops[i] == last){
            op1 = 1 + make_bottom_equal(i+1,tops[i],tops,bottom);
        }
        
        if(last == -1 || bottom[i] == last) {
            op2 = make_bottom_equal(i+1,bottom[i],tops,bottom);
        }
        
        return dp2[i][last+1] = min(op1,op2);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int ans =  min(make_top_equal(0,-1,tops,bottoms), make_bottom_equal(0,-1,tops,bottoms));
        return (ans >= 1e9) ? -1: ans;
    }
};