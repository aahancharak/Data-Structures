#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* start = nullptr;
        unordered_map<int, Employee*>mappah;
        for(auto ele:employees){
            if(ele->id==id) start = ele;
            if(mappah.find(ele->id)==mappah.end())mappah[ele->id] = ele;
        }
        if(start == nullptr) return 0;
         queue<Employee*>q;
        q.push(start);
        int importance = 0;
        
        while(!q.empty()){
            Employee* first = q.front();
            importance+=(first->importance);
            q.pop();
            for(int ele:first->subordinates){
                q.push(mappah[ele]);
            }
            
        }
        
        return importance;
    }
    
  
};