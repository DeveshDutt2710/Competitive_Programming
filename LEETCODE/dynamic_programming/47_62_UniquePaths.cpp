/*

https://leetcode.com/problems/unique-paths/
62_UniquePaths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


*/



class Solution {
public:
    vector<vector<int>> dp;
    int uniquePath(int m, int n) {
        if(m<=0||n<=0)
        {
            return 0;
        }
        if(dp[m][n] != -1)
        {
            return dp[m][n];
        }
        if(m==1 && n==1)
        {
            return 1;
        }
        else
        {
            return dp[m][n] = uniquePath(m-1,n) + uniquePath(m,n-1);
        }
    }
    
    int uniquePaths(int m, int n)
    {
        dp.resize(m+1,vector<int>(n+1,-1));
        return uniquePath(m,n);
        
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};