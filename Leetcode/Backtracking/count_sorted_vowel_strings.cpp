#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    Solution(){
        vowels = {"a", "e", "i", "o", "u"};
    }
    int countVowelStrings(int n) {
        int solution=0;
        vector<string>curString;
        backtrack(n,solution, curString, 0);
        return solution;
    }
    void backtrack(int n, int&solution, vector<string>&curString, int idx){
        if(curString.size()==n){
            solution+=1;
            return;
        }
        for(int i=idx; i<vowels.size(); i++){
            curString.push_back(vowels[i]);
            
            backtrack(n, solution, curString, i);
            //backtrack and explore further solutions
            curString.pop_back();
        }
    }
    vector<string>vowels;
};