#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp = vector<int>(arr.size()+1, -1);
        return solve(arr, k, 0, dp);
    }
    
    int solve(vector<int>&arr, int k, int idx, vector<int>&dp){
        int i= idx;
        if(idx>arr.size()-1) return 0;
        if(idx==arr.size()-1) return arr[idx];
        if(dp[idx]!=-1) return dp[idx];
        int curMax = arr[idx];
        int maxVal = -1;
        for(int j=i; j-i+1<=k; j++){
            if(j>arr.size()-1) break;
            curMax = max(curMax, arr[j]);
            maxVal = max(maxVal, curMax*(j-i+1)+solve(arr, k, j+1, dp));
        }
        
        dp[idx] = maxVal;
        return maxVal;
            
    }
};
