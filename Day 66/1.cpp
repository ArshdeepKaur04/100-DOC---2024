/*
Question "895. Maximum Frequency Stack" on Leetcode
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.
*/

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> st;
    int maxFreq = 0;

    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        if(st[maxFreq].empty()) {
            maxFreq--;
        }
        int x = st[maxFreq].top();
        freq[x]--;
        st[maxFreq].pop();
        return x;
    }
};