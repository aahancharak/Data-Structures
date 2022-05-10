#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool canBeAttacked(vector<string>&board, int i, int j){
        //check in same column
        for(int k=0; k<i; k++){
            if(board[k][j]=='Q') return true;
        }
        //check in same row
        for(int k=0; k<j; k++){
            if(board[i][k]=='Q') return true;
        }
        //check left diagonally
        int row_s = i - min(i, j);
        int col_s = j - min(i, j);
        
        while(row_s <i && col_s <j){
            if(row_s >=0 && row_s<board.size() && col_s>=0 && col_s<board[0].size()){
                if(board[row_s][col_s]=='Q') return true;
            }
            row_s++;
            col_s++;
        }
        
        //check right diagonally
        row_s = i - max(i, j);
        col_s = j+ max(i, j);
        
        while(row_s<i && col_s>j){
              if(row_s >=0 && row_s<board.size() && col_s>=0 && col_s<board[0].size()){
                if(board[row_s][col_s]=='Q') return true;
            }
            row_s++;
            col_s--;
        }
        return false;
    }
    
    void solve(int n, vector<vector<string>>&solutions, vector<string>&board, int row){
        
        //loop through each column on the board
        for(int col=0; col<n; col++){
            if(!canBeAttacked(board, row, col)){
                //add queen to the solution
                board[row][col] = 'Q';
                //if cur row is last, add solution
                if(row+1==n) solutions.push_back(board);
                //else move to next row
                else{
                    solve(n, solutions, board, row+1);
                }
                //backtrack
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
            vector<string>board = vector<string>(n, string(n,'.'));
            vector<vector<string>>solutions;
            solve(n, solutions, board, 0);
        return solutions;
    }
};