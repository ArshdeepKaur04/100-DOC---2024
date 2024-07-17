/*
Question:
Implement a stack using two queues. The stack should support standard operations like push, pop, and top.
*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

// Push element x onto stack
void push(int x) {
    // Push x to q2
    q2.push(x);
    
    // Push all elements of q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    // Swap the names of q1 and q2
    swap(q1, q2);
}

// Removes the element on top of the stack and returns that element
int pop() {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    int topElement = q1.front();
    q1.pop();
    return topElement;
}

// Get the top element
int top() {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    
    return q1.front();
}

int main() {
    push(1);
    push(2);

    cout << top() << endl;
    cout << pop() << endl;
    cout << top() << endl;
}