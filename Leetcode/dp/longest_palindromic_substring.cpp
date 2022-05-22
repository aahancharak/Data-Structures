#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size()-1;
       vector<vector<int>>dp = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        int maxi = -1;
        int start=0;
        int end=0;
        for(int i=n; i>=0; i--){
            for(int j=i; j<=n; j++){
                if(s[i]==s[j]){
                    if(j-i+1<3 || dp[i+1][j-1]!=0)dp[i][j]=j-i+1;
                }
                if(dp[i][j]>maxi){
                    maxi = dp[i][j];
                    start=i;
                    end=j;
                    
                }

            }
        }
        return s.substr(start, end-start+1);
    }
};
