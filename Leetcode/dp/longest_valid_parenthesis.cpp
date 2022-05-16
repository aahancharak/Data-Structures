#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
            vector<int>dp = vector<int>(s.size(), 0);
        
        for(int i=0; i<s.size(); i++){
               if(s[i]=='(') continue;
                else if(s[i]==')'){
                    if(i-1>=0 && s[i-1]=='('){
                        dp[i]+=2;
                        if(i-2>=0)dp[i]+=dp[i-2];
                    }
                    
                    if(i-1>=0 && s[i-1]==')'){
                        if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                            dp[i]+=(2+dp[i-1]);
                            if(i-dp[i-1]-2>=0)dp[i]+=dp[i-dp[i-1]-2];
                        }
                    }
                }
        
        }
        
        int curMax=0;
      for(int i=0; i<dp.size();i++){
          curMax = max(curMax, dp[i]);
      }
        return curMax;
    }
};
