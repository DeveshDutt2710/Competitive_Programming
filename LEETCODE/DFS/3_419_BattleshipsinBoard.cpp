/*

https://leetcode.com/problems/battleships-in-a-board/
419_BattleshipsinBoard

Given an m x n matrix board where each cell is a 
battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board.
In other words, they can only be made of the shape 
1 x k (1 row, k columns) or k x 1 (k rows, 1 column), 
where k can be of any size. At least one horizontal or vertical cell 
separates between two battleships (i.e., there are no adjacent battleships).
*/


class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i<0||i>=board.size()||j<0||j>=board[0].size())
        {
            return;
        }
        if(board[i][j]=='.')
        {
            return;
        }
        
        board[i][j]='.';
        
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='X')
                {
                    dfs(board,i,j);
                    count++;
                }
            }
        }
        return count;
        
    }
};