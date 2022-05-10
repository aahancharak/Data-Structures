#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
    
public:
    Solution(){
        mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }
    vector<string> letterCombinations(string digits) {
        vector<string>solutions;
        solve(digits, 0, solutions, "");
        return solutions;
    }
    //recursive approach
    void solve(string digits, int i, vector<string>&sol, string comb){
        if(digits=="") return;
        if(i==digits.size()){
            sol.push_back(comb);
            return;
        }
        for(char c:mappings[digits[i] - '2']){
            solve(digits, i+1, sol, comb+c);
        }
        
    }
    
    vector<string>mappings;
};