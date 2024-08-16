/*
Question "786. K-th Smallest Prime Fraction" on Leetcode
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. 
You are also given an integer k. For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] /
arr[j]. Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where 
answer[0] == arr[i] and answer[1] == arr[j].
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto compare = [](tuple<double, int, int>& a, tuple<double, int, int>& b) {
        return get<0>(a) > get<0>(b);
    };

    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, decltype(compare)> pq(compare);

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        double primeFraction = 1.0 * arr[i] / arr[n - 1];
        pq.push(make_tuple(primeFraction, i, n - 1));
    }

    vector<int> res(2);
    while (k > 0) {
        auto curVal = pq.top();
        pq.pop();
        int numIndex = get<1>(curVal);
        int denIndex = get<2>(curVal) - 1;

        if (numIndex < denIndex) {
            double primeFraction = 1.0 * arr[numIndex] / arr[denIndex];
            pq.push(make_tuple(primeFraction, numIndex, denIndex));
        }
        k--;
        if (k == 0) {
            res[0] = arr[numIndex];
            res[1] = arr[denIndex + 1];
        }
    }
    return res;
    }
};