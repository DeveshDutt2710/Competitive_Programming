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
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[j][j] = solve(s,i+1,j-1);
        }
        else
        {
            return dp[i][j] = 1 + min(solve(s,i+1,j), solve(s,i,j-1));
        }
    }
    int minInsertions(string s) {
        dp.resize(s.length(), vector<int>(s.length(),-1));
        return solve(s,0,s.length()-1);
    }
};