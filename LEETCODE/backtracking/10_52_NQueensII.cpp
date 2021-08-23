/*
https://leetcode.com/problems/n-queens-ii/

52_NQueensII

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/



class Solution {
public:
    
    bool isValid(vector<vector<int>>& board, int row, int column)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][column]==1)
                return false;
        }
        for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]==1)
                return false;
        }
        for(int i=row-1,j=column+1;i>=0 && j<board.size();i--,j++)
        {
            if(board[i][j]==1)
                return false;
        }
        return true;
    }
    void backtrack(vector<vector<int>>& board, int r, int c, int &count)
    {
        if(r == board.size())
        {
            count++;
            return;
        }
        
        for(int i=0;i<c;i++){
            if(isValid(board,r,i)){
                board[r][i] = 1;
                backtrack(board,r+1,c, count);
                board[r][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n,vector<int>(n));
        int count = 0;
        backtrack(board,0,n, count);
        return count;
    }
};