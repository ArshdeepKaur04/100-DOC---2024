/*
Question "Kth Smallest" on Geeks for Geeks
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth
smallest element in the given array. It is given that all array elements are distinct.
Note:-  l and r denotes the starting and ending index of the array.
*/

#include <iostream>
#include <queue>
using namespace std;

class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
    
        for (int i = l; i < l + k; ++i) { 
            pq.push(arr[i]); 
        } 
        
        for (int i = l + k; i <= r; ++i) { 
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};