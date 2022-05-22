#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size()-1;
        vector<vector<bool>>dp = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
        int resVal = 0;
        for(int i=n; i>=0;i--){
            for(int j=i; j<=n; j++){
                //both strings equal
                if(s[i]==s[j]){
                    //string less than 3 size = palindrome and if not, if inner string palindrome, solution found
                    if(j-i+1<3 || dp[i+1][j-1]) dp[i][j] = true;
                }
                
                if(dp[i][j])resVal++;
            }
        }
        
        return resVal;
    }
};
