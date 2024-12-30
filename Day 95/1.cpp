/*
Question "Union of Arrays with Duplicates" on GfG
Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays. The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std; 

class Solution {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        set<int> count;
        
        for(auto i: a) {
            count.insert(i);
        }
        
        for(auto i: b) {
            count.insert(i);
        }
        
        return count.size();
    }
};