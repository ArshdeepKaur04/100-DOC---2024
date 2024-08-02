/*
Question "849. Maximize Distance to Closest Person" on Leetcode
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat,
and seats[i] = 0 represents that the ith seat is empty (0-indexed). There is at least one empty seat, and at least
one person sitting. Alex wants to sit in the seat such that the distance between him and the closest person to him
is maximized. Return that maximum distance to the closest person.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans{}, count{};
        bool isFound{false};
        for(int i{}; i < (int)seats.size(); ++i){
            if(seats[i] == 0)
                ++count;
            else if(seats[i] == 1){
                if(isFound)
                    ans = max(ans, (count + 1) / 2);
                else
                    ans = max(ans, count);
                isFound = true;
                count = 0;
            }
        }
        if(count)
            ans = max(ans, count);
        return ans;
    }
};