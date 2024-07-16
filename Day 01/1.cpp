/*
Question: 
Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the
bar into a contiguous segment such that:
1. The segment length matches Raju's birth month.
2. The sum of the numbers in the segment equals Raju's birth day.

Write a code for the same which will print the number of valid ways to divide the bar.
*/

#include <iostream>
using namespace std;

int main() {
    int candy[10], n, day, month, count = 0;
    cout << "Enter the number of chocolate squares: ";
    cin >> n;
    cout << "Enter the chocolate squares: ";
    for (int i=0; i<n; i++) {
        cin >> candy[i];
    }

    cout << "Enter the day: ";
    cin >> day;
    cout << "Enter the month: ";
    cin >> month;

    for (int i = 0; i <= n - month; ++i) {
        int sum = 0;
        for (int j = 0; j < month; ++j) {
            sum += candy[i + j];
        }
        if (sum == day) {
            count++;
        }
    }

    cout << count << endl;
}