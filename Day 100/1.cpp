/*
Question "973. K Closest Points to Origin" on Leetcode
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0). The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2). You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<vector<int>, int>> distance;

        for(auto& point: points) {
            int x = point[0];
            int y = point[1];
            int distSquared = x * x + y * y;  // Use squared distance to avoid floating-point issues
            distance.push_back({point, distSquared});
        }

        sort(distance.begin(), distance.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            return a.second < b.second;
        });

        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(distance[i].first);
        }

        return result;
    }
};