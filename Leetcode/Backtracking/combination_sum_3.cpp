#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
     vector<int>nums(9, -1);
     vector<vector<int>>combinations;
        backtrack(k, n, combinations, nums, 1);
        return combinations;
    }
    
    void backtrack(int k, int n, vector<vector<int>>& combinations, vector<int>&nums, int start ){
        if(k==0 && n==0){
            vector<int>vals;
            string res;
            int idx=0;
            for(int ele:nums){
                if(ele!=-1){
                res+=to_string(idx+1);
                vals.push_back(idx+1);
                }
                idx++;
            }
            if(combs.find(res)==combs.end()) {
                combinations.push_back(vals);
                combs.insert(res);
            }
            return;
        }
        if(k<=0 || n<=0) return;
        //go through all possible solutions
        for(int i=start; i<=9; i++){
            //we havent considered solution yet, pruning
            if(nums[i-1]==-1){
                //add solution to set
                nums[i-1]=1;
                //check if we reach k and n-i is zero
                backtrack(k-1, n-i, combinations, nums, i+1);
                //backtrack and remove current solution
                nums[i-1]=-1;
            }
        }
    }
    unordered_set<string>combs;
};