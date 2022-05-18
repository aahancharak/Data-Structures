#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjList = vector<vector<int>>(n);
        //add all edges to adjacency list
        for(vector<int>& ele:connections){
            int first = ele[0];
            int second = ele[1];
            adjList[first].push_back(second);
            adjList[second].push_back(first);
        }
        //visit time for each node in the graph
        vector<int>d = vector<int>(n, -1);
        //lowest time node we can reach from current node
        vector<int>low = vector<int>(n, -1);
        //parent of current node in dfs tree
        vector<int>parent = vector<int>(n, -1);
        visited = vector<bool>(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
            dfs(adjList, d, low, parent, i);
                
            }
        }
    
        
        return solutions;
          
    }
    
    void dfs(vector<vector<int>>& c, vector<int>&d, vector<int>& low, vector<int>&parent, int i){
        int children = 0;
        d[i] = time;
        low[i]=d[i];
        time++;
        visited[i] = true;
        if(parent[i]==-1 && c[i].size()==1){
            solutions.push_back({i,c[i][0]});
            visited[c[i][0]]=true;
            return; 
        }
       for(int v:c[i]){
            //not visited the node
            if(visited[v]==false){
                parent[v]=i;
                children++;
                dfs(c, d, low, parent, v);
                //check if subtree is connected to a node ancestor to the parent
                low[i] = min(low[i], low[v]);
                //condition for articulation i.e no back connection
                if(low[v]>d[i]){
                    vector<int>sol = {i, v};
                    solutions.push_back(sol);
                }
            }
            //if vertex is not the parent and if the node can reach an ancestor so can the child.
            else if(v!=parent[i]){
                low[i] = min(low[i], d[v]);
            }
            
        }
    
        
    }
    vector<vector<int>>solutions;
    int time = 0;
    vector<bool>visited;
};
