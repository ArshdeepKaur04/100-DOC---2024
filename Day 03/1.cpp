/*
Question:
A function to determine if a given sentence includes every letter of the English alphabet at least once. The 
function should be case insensitive and return "complete" if the sentence contains every letter, otherwise return
"incomplete".
*/

#include <iostream>
using namespace std;

bool isComplete(int arr[]) {
    for(int i=0; i<26; i++) {
        if (arr[i] == 0) {
            return 0;     
        }
    }
    return 1;
}

int main() {
    int count[26] = {0};
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    int n = s.length(), index = 0;
    for (int i=0; i<n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            index = s[i] - 'a';
        }
        else {
            index = s[i] - 'A';
        }
        count[index]++;
    }

    if(isComplete(count)) {
        cout << "Complete" << endl;
    }
    else {
        cout << "Incomplete" << endl;
    }
}