/*
Question "155. Min Stack" on Leetcode
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st, s2;
    MinStack() { 
    }
    
    void push(int val) {
        if(s2.empty() || val <= s2.top()) {
            s2.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if(st.top() == s2.top()) {
            s2.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s2.top();
    }
};