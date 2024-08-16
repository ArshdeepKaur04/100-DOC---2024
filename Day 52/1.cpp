/*
Question "295. Find Median from Data Stream" on Leetcode
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle 
value, and the median is the mean of the two middle values. Implement the MedianFinder class.
*/

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxpq; // maxHeap
    priority_queue<int, vector<int>, greater<int>> minpq; // minHeap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxpq.empty() || maxpq.top() > num) {
            maxpq.push(num);
        }
        else {
            minpq.push(num);
        }

        //shifting the elements in case the difference of the elements in maxHeap & minHeap is greater than 1
        if(maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size() + 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(maxpq.size() == minpq.size()) {
            return(maxpq.top() + minpq.top()) / 2.0;
        }
        else {
            if(maxpq.size() > minpq.size()) {
                return maxpq.top();
            }
            else {
                return minpq.top();
            }
        }
    }
};