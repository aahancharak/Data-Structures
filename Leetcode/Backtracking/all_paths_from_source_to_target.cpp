#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>paths;
        vector<int>path;
        path.push_back(0);
        backtrack(paths, graph, path, 0);
        
        return paths;
    }
    
    void backtrack(vector<vector<int>>&paths, vector<vector<int>>&graph, vector<int>& path, int cur){
        int n = graph.size() - 1;
        if(cur==n){
         paths.push_back(path);
            return;
        }
        
        for(auto node: graph[cur]){
           // add node to solution
            path.push_back(node);
            //backtrack
            backtrack(paths, graph, path, node);
            //explore other solution candidates
            path.pop_back();
        }
    }
};