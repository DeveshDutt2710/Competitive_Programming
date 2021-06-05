/*
https://leetcode.com/problems/regular-expression-matching/

10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:

0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    bool solver(string &s, string &p, int a, int b, vector<vector<int>> &dp)
    {
        if(dp[a][b] != -1)
        {
            return dp[a][b];
        }
        
        if(a>=s.length() && b>=p.length())
        {
            return dp[a][b] = true;
        }

        if(b>=p.length())
        {
            return dp[a][b] = false;
        }
        
        bool match = (a<s.length() && (s[a] == p[b] || p[b] == '.'));
        
        if(b<p.length() && p[b+1] == '*')
        {
            return dp[a][b] = solver(s,p,a,b+2,dp) || (match && solver(s,p,a+1,b,dp));
        }
        if(match)
        {
            return dp[a][b] = solver(s,p,a+1,b+1,dp);
        }
        
        return dp[a][b] = false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solver(s,p,0,0,dp);
        
    }
};