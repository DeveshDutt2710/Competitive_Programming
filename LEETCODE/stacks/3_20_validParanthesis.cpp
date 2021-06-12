/*
https://leetcode.com/problems/valid-parentheses/

20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/


class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                s.push(str[i]);
            }
            else if(str[i] == ')' && !s.empty())
            {
                if(s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else if(str[i] == '}' && !s.empty())
            {
                if(s.top() == '{')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else if(str[i] == ']' && !s.empty())
            {
                if(s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
                
            }
            else if((str[i] == ')' || str[i] == ']' || str[i] == '}') && s.empty())
            {
                return false;
            }
            
        }
        return s.empty()?true:false;
        
    }
};