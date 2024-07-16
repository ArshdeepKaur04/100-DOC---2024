/*
Question "977. Squares of a Sorted Array" on leetcode - Did it myself :))
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in
non-decreasing order.
*/

//Answer that is running on the vs code
/*
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> ans;

    for (int i:nums) {
        int temp = i*i;
        ans.push_back(temp);
    }

    for (int i:ans) {
        cout << i << " ";
    } cout << endl;

    sort(ans.begin(), ans.end());
    for (int i:ans) {
        cout << i << " ";
    }
}
*/

//Answer submitted
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;

        for (int i:nums) {
            int temp = i*i;
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};
*/