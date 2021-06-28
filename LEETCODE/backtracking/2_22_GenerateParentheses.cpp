/*

https://leetcode.com/problems/generate-parentheses/

22_GenerateParentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/


class Solution {
public:
    vector<string> res;
    void helper(string s, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }
        if(open > 0)
        {
            helper(s+"(",open-1,close);
        }
        if(close > open)
        {
            helper(s+")",open, close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        helper("",n,n);
        
        return res;
    }
};