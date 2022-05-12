#include<iostream>
#include<stdlib.h>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<int>perm;
        unordered_map<int, int>mappings;
        for(int ele:nums){
            mappings[ele]++;
        }
        backtrack(perm, mappings, nums.size());
        return solutions;
    }
    
    void backtrack(vector<int>&perm, unordered_map<int, int>& nums, int n){
        if(perm.size()==n){
            solutions.push_back(perm);
            return;
        }
        
        for(auto& pair:nums){
             int num = pair.first;
             int total = pair.second;
            if(total>0){
                //add to perm
                nums[num]--;
                perm.push_back(num);
                //explore other solutions
                backtrack(perm, nums, n);
                //remove from perm
                perm.pop_back();
                nums[num]++;    
            }
        }
    }
    vector<vector<int>>solutions;

};