#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int start = 0;
        int end = start + k - 1;
        unordered_set<string>present;
        while(start < s.size() && end < s.size()){
            string sub = s.substr(start, end - start + 1);
            present.insert(sub);
            //increment start and end
            start++;
            end++;
        }
        
        if(present.size()==pow(2,k)) return true;
        
        return false;
    }
};
