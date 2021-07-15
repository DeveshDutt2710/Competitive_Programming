/*
https://leetcode.com/problems/longest-common-subsequence/

1143_LongestCommonSubsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/


class Solution {
public:
    int helper(string &a, string &b, int n, int m, int dp[][1001])
    {
        
        if(n==0||m==0)
        {
            return 0;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if(a[n-1] == b[m-1])
        {
            return dp[n][m] = 1+helper(a,b,n-1,m-1,dp);
        }
        else
        {
            return dp[n][m] = max(helper(a,b,n-1,m,dp), helper(a,b,n,m-1,dp));
        }
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.length();
        int m = text2.length();
        
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return helper(text1, text2,n,m,dp);
        
    }
};