/*
Question:
Check if a given string of brackets is balanced. The brackets include (), {}, and [].
*/

#include <iostream>
#include <stack>
using namespace std;

string isBalanced(string& str) {
    stack<char> stack;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return "NO";
            }
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return "NO";
            }
        }
    }

    return stack.empty() ? "YES" : "NO";
}

int main() {
    string input;
    cout << "Enter the string of brackets: ";
    cin >> input;

    cout << isBalanced(input) << endl;
}