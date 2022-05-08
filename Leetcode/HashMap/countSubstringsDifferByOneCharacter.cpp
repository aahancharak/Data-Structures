#include<iostream>
using namespace std;
class Solution {
public:
    int countSubstrings(string s, string t) {
        int total_mismatches = 0;
        //every start pair
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<t.size(); j++){
                int mismatch = 0;
                for(int sz=0; i+sz < s.size() && j+sz<t.size(); sz++){
                    if(s[sz+i] != t[sz+j]){
                        mismatch++;
                        if(mismatch >1) break;
                     }
                    total_mismatches+=mismatch;
                }

            }
        }
        return total_mismatches;
    }
};