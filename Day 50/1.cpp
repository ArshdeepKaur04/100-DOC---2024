/*
Question "1011. Capacity To Ship Packages Within D Days" on Leetcode
A conveyor belt has packages that must be shipped from one port to another within days days. The ith package on the
conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the 
order given by weights). We may not load more weight than the maximum weight capacity of the ship. Return the least
weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within given 
days.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDays(vector<int> &weights, int cap) {
        int days=1, load=0;
        for(int i=0; i<weights.size(); i++) {
            if(weights[i] + load > cap) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high) {
            int mid = (low + high) / 2;
            int numberOfDays = findDays(weights, mid);
            if (numberOfDays <= days) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};