/*
https://leetcode.com/problems/maximal-square/

221_MaximalSquare

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int n = M.size();
        int m = M[0].size();
        if(M.empty())
        {
            return 0;
        }
        int size = 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || M[i][j]=='0')
                {
                    dp[i][j] = M[i][j]-'0';
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1; 
                }
                size = max(size,dp[i][j]);
            }
        }
        return size*size;
        
    }
};