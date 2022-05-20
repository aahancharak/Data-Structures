#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
      int  n = grid.size()-1;
        int m = grid[0].size()-1;
        vector<vector<long int>>dp = vector<vector<long int>>(n+1, vector<long int>(m+1, 0));
        if(grid[n][m]==1) return 0;
        //fill in reverse order
        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                //last row
                if(i==n){
                    if(grid[i][j]!=1){
                    if(i==n && j==m)dp[i][j]=1;
                    else dp[i][j] = dp[i][j+1];
                    }
                    else dp[i][j]=0;
                }
                
                else if(j==m){
                    if(grid[i][j]!=1){
                        dp[i][j] = dp[i+1][j];
                    }
                    else dp[i][j]=0;
                }
                else{
                    if(grid[i][j]!=1)dp[i][j]=dp[i+1][j] + dp[i][j+1];
                    else dp[i][j]=0;
                }
            }
        }
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return dp[0][0];
    }
};
