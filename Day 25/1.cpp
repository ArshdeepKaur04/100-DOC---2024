/*
Question "27. Remove Element" on leetcode - Mostly did it myself, except 1 runtime error :))
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the 
elements may be changed. Then return the number of elements in nums which are not equal to val.
*/

#include <iostream>
#include <vector>
using namespace std;

//my answer which is giving runtime error
/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0, end=nums.size()-1;

        while(start == end && nums[start] == val) {
            return 0;
        }
        
        while(start <= end) {
            while(nums[start] != val) {
            start++;
           }
           while(nums[end] == val && end != 0) {
            end--;
           }
           if (start <= end) {
            swap(nums[start++], nums[end--]);
           }
        }

        int ans = 0;
        for(int i:nums) {
            if (i == val) {
                break;
            }
            ans++;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1};
    int ans = removeElement(nums, 1);
    cout << ans << endl;
}
*/

//corrected answer given by ChatGPT
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start=0, end=nums.size()-1;
        
        while (start <= end) {
            while (start <= end && nums[start] != val) {
                start++;
            }
            while (start <= end && nums[end] == val) {
                end--;
            }
            if (start < end) {
                swap(nums[start++], nums[end--]);
            }
        }

        return start;
    }
};