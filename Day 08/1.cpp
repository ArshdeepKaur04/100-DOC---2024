/*
#include <iostream>
#include <stack>
using namespace std;

int equalHeights(stack<int> stack1, stack<int> stack2, stack<int> stack3) {
    int height1 = 0, height2 = 0, height3 = 0;
    stack <int> temp1(stack1);
    stack <int> temp2(stack2);
    stack <int> temp3(stack3);
    
    //calculating the height of each cylinder
    while(!temp1.empty()) {
        height1 += temp2.top();
        temp2.pop();
    }
    cout << height1 << endl;
    while(!temp2.empty()) {
        height2 += temp2.top();
        temp2.pop();
    }
    cout << height2 << endl;
    while(!temp3.empty()) {
        height3 += temp3.top();
        temp3.pop();
    }
    cout << height3 << endl;
    return 0;
}

int main() {
    stack <int> stack1;
    stack <int> stack2;
    stack <int> stack3;
    int n1, n2, n3, temp;

    cout << "Enter the number of elements in stack 1: ";
    cin >> n1;
    cout << "Enter the elements of stack 1: ";
    for (int i=0; i<n1; i++) {
        cin >> temp;
        stack1.push(temp);
    }
    
    cout << "Enter the number of elements in stack 2: ";
    cin >> n2;
    cout << "Enter the elements of stack 2: ";
    for (int i=0; i<n2; i++) {
        cin >> temp;
        stack2.push(temp);
    }

    cout << "Enter the number of elements in stack 3: ";
    cin >> n3;
    cout << "Enter the elements of stack 3: ";
    for (int i=0; i<n3; i++) {
        cin >> temp;
        stack3.push(temp);
    }
    
    int ans = equalHeights(stack1, stack2, stack3);
    cout << endl << ans;
}
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the height of the stack
int calculateHeight(const vector<int>& stack) {
    int height = 0;
    for (int cylinder : stack) {
        height += cylinder;
    }
    return height;
}

int equalizeStackHeights(vector<int>& stack1, vector<int>& stack2, vector<int>& stack3) {
    // Convert the vectors to stacks
    stack<int> s1, s2, s3;
    for (int i=stack1.size()-1; i>=0; --i) {
        s1.push(stack1[i]);
    }
    for (int i=stack2.size()-1; i>=0; --i) {
        s2.push(stack2[i]);
    }
    for (int i=stack3.size()-1; i>=0; --i) {
        s3.push(stack3[i]);
    }
    
    // Calculate the initial heights
    int h1 = calculateHeight(stack1);
    int h2 = calculateHeight(stack2);
    int h3 = calculateHeight(stack3);
    
    while (!(h1 == h2 && h2 == h3)) {
        if (h1 >= h2 && h1 >= h3) {
            h1 -= s1.top();
            s1.pop();
        } else if (h2 >= h1 && h2 >= h3) {
            h2 -= s2.top();
            s2.pop();
        } else if (h3 >= h1 && h3 >= h2) {
            h3 -= s3.top();
            s3.pop();
        }
    }
    
    return h1; // or h2 or h3 as they are equal
}

int main() {
    int n1, n2, n3;
    
    cout << "Enter the number of cylinders in stack 1: ";
    cin >> n1;
    vector<int> stack1(n1);
    cout << "Enter the heights of cylinders in stack 1: ";
    for (int i=0; i<n1; ++i) {
        cin >> stack1[i];
    }
    
    cout << "Enter the number of cylinders in stack 2: ";
    cin >> n2;
    vector<int> stack2(n2);
    cout << "Enter the heights of cylinders in stack 2: ";
    for (int i=0; i<n2; ++i) {
        cin >> stack2[i];
    }
    
    cout << "Enter the number of cylinders in stack 3: ";
    cin >> n3;
    vector<int> stack3(n3);
    cout << "Enter the heights of cylinders in stack 3: ";
    for (int i=0; i<n3; ++i) {
        cin >> stack3[i];
    }
    
    cout << endl << equalizeStackHeights(stack1, stack2, stack3) << endl;
}