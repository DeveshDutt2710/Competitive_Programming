/*
https://leetcode.com/problems/word-search/

79_WordSearch

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/


class Solution {
public:
    
    bool solve(vector<vector<char>>&board,int row, int column,string &word)
    {
        if(!word.size())
        {
            return true;
        }
        if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size() || board[row][column] != word[0])
        {
            return false;
        }
        char c = board[row][column];
        string s = word.substr(1);
        board[row][column] = '*';
        
        bool res = solve(board,row+1,column,s)||solve(board,row-1,column,s)||solve(board,row,column+1,s)||
                    solve(board,row,column-1,s);
        
        board[row][column] = c;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(board,i,j,word))
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};