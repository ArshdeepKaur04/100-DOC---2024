/*
Question "11. Container with Most Water" on Leetcode
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of
the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such 
that the container contains the most water. Return the maximum amount of water a container can store.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size()-1;

        while(l < r) {
            int area = (r-l) * min(height[l], height[r]);
            res = max(res, area);

            if(height[l] < height[r]) {
                l += 1;
            }
            else {
                r -= 1;
            }
        }

        return res;
    }
};