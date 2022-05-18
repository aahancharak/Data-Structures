#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
     unordered_map<int, vector<int>>adjList;
        unordered_map<int,int>freq;
        vector<int>solution;

        for(vector<int>&ele:adjacentPairs){
            int first = ele[0];
            int second = ele[1];
            if(adjList.find(first)==adjList.end()) adjList[first] = vector<int>();
            if(adjList.find(second)==adjList.end())adjList[second]=vector<int>();
            adjList[first].push_back(second);
            adjList[second].push_back(first);
            freq[first]+=1;
            freq[second]+=1;
        }
        //get starting points'
        int start = -1;
        for(auto ele:freq){
            if(ele.second==1){
                start=ele.first;
                break;
            }
        }
        //visited
        unordered_set<int>visited;
        queue<int>kooh;
        kooh.push(start);
        visited.insert(start);
        while(!kooh.empty()){
        int node = kooh.front();
        //push to solution
        solution.push_back(node);
        kooh.pop();

        //pop the node
            for(int ele:adjList[node]){
                if(visited.find(ele)!=visited.end())continue;
                visited.insert(ele);
                kooh.push(ele);
            }
            
        }
        
        return solution;
    }
};
