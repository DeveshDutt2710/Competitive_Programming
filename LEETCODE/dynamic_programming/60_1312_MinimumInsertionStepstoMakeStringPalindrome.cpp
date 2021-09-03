/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

1312_MinimumInsertionStepstoMakeStringPalindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.



*/


class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, int i, int j)
    {
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(i>=j)
        {
            return dp[i][j]=0;
        }
        if(s[i]==s[j])
        {
            return dp[i][j] = solve(s,i+1,j-1);
        }
        else
        {
            return dp[i][j] = 1 + min(solve(s,i+1,j), solve(s,i,j-1));
        }
        
    }
    int minInsertions(string s) {
        int n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return solve(s,0,n-1);
    }
};