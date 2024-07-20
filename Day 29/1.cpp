/*
Question "769. Max Chunks To Make Sorted" on leetcode
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating
them, the result should equal the sorted array. Return the largest number of chunks we can make to sort the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maximum = 0;
        int chunks = 0;

        for (int i=0; i<arr.size(); i++) {
            maximum = max(arr[i], maximum);
            if (i == maximum) {
                chunks++;
            }
        }

        return chunks;
    }
};