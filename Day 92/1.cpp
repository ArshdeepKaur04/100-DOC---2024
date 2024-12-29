/*
Question "990. Satisfiability of Equality Equations" on Leetcode
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names. Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fetchParent(int index, int parent[]) {
        if(parent[index] == index) {
            return index;
        }
        return fetchParent(parent[index], parent);
    }

    bool equationsPossible(vector<string>& equations) {
        int parent[26];
        for(int i=0; i<26; i++) {
            parent[i] = i;
        }

        for(auto equation: equations) { 
            char equality = equation[1];
            if(equality == '=') {
                int var1 = fetchParent(equation[0]-'a', parent);
                int var2 = fetchParent(equation[3]-'a', parent);

                if(var1 != var2) {
                    parent[var2] = var1;
                }
            }
        }

        for(auto equation: equations) {
            char equality = equation[1];
            if(equality == '!') {
                int var1 = fetchParent(equation[0]-'a', parent);
                int var2 = fetchParent(equation[3]-'a', parent);

                if(var1 == var2) {
                    return false;
                }
            }
        }

        return true;
    }
};