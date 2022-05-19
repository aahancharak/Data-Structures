#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
#include<unordered_map>
#include<utility>
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //direction vector
        int sol = 0;
        unordered_set<string>visited;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size();j++){
                sol = max(sol, dfs(matrix, i, j, visited));
            }
        }
        return sol;
        
    }
    
    int dfs(vector<vector<int>>&matrix, int i, int j, unordered_set<string>visited){
        string code_m = to_string(i) + " " + to_string(j);
        if(mappah.find(code_m)!=mappah.end()) return mappah[code_m];
        int maxi = 1;
        int n1  = matrix.size();
        int n2 = matrix[0].size();
        for(pair ele:directions){
            int x = i + ele.first;
            int y = j + ele.second;
            string code = to_string(x) + " " + to_string(y);
            //we haven't visited yet
            if(x>=0 && y>=0 && x<=n1-1 && y<=n2-1 && visited.find(code)==visited.end()){
                //if the node is increasing
                if(matrix[i][j] < matrix[x][y]){
                    //add to solution
                    visited.insert(code);
                    //explore other possiblilites
                    maxi = max(maxi, 1+dfs(matrix, x, y,visited));
                    //backtrack
                    visited.erase(code);
                }
            }
        }
        mappah[code_m] = maxi;
        return maxi;
    }
vector<pair<int, int>>directions = {{-1,0},{0, 1}, {1,0}, {0, -1}};
unordered_map<string, int>mappah;


};
