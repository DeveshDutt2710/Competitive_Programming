/*

https://leetcode.com/problems/interleaving-string/

97. Interleaving String

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
*/


class Solution {
public:
    int dp[101][101];
    bool solve(string s1, string s2, string s3, int l1, int l2, int n)
    {
        if(l1 >= 0 && l2 >= 0 && dp[l1][l2] != -1)
        {
            return dp[l1][l2];
        }
        if(l1 < 0 && l2 < 0 && n < 0)
        {
            return true;
        }
        if(l1 >= 0 && n >= 0 && s1[l1] == s3[n] && l2 >= 0 && s2[l2] == s3[n])
        {
            return dp[l1][l2] = (solve(s1,s2,s3,l1-1,l2,n-1) || solve(s1,s2,s3,l1,l2-1,n-1));
        }
        else if(l1 >= 0 && n >= 0 && s1[l1] == s3[n])
        {
            return solve(s1,s2,s3,l1-1,l2,n-1);
        }
        else if(l2 >= 0 && n >= 0 && s2[l2] == s3[n])
        {
            return solve(s1,s2,s3,l1,l2-1,n-1);
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
        
    }
};
