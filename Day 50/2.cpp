/*
Question "875. Koko Eating Bananas" on Leetcode
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone 
and will come back in h hours. Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some
pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them 
instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to finish 
eating all the bananas before the guards return. Return the minimum integer k such that she can eat all the bananas
within h hours.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int check(vector<int>& piles, int h,int mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]/mid);
            if(piles[i]%mid!=0){
                ans++;
            }
        }
        return ans<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=1;
        int high=piles[n-1];

        while(low<high){
            int mid=(low+high)/2;
            if(check(piles,h,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};