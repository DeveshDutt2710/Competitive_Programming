/*
https://leetcode.com/problems/basic-calculator-ii/

227. Basic Calculator II

Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/


class Solution {
public:
    int getPriority(char &c)
    {
        if(c == '+' || c == '-')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
    int performOperation(char &c, int &a, int &b)
    {
        if(c == '+')
        {
            return a+b;
        }
        else if(c == '-')
        {
            return a-b;
        }
        else if(c == '*')
        {
            return a*b;
        }
        else
        {
            return a/b;
        }
    }
    
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        
        for(int i=0;i<s.size();)
        {
            while(i<s.size() && s[i] == ' ')
            {
                ++i;
            }
            
            if(i<s.size() && isdigit(s[i]))
            {
                int number = 0;
                while(i<s.size() && isdigit(s[i]))
                {
                    number = number*10 + (s[i] - '0');
                    ++i;
                }
                nums.push(number);
            }
            else if(i<s.size())
            {
                while(!ops.empty() && getPriority(s[i]) <= getPriority(ops.top()))
                {
                    int second = nums.top();
                    nums.pop();
                    int first = nums.top();
                    nums.pop();
                    nums.push(performOperation(ops.top(), first, second));
                    ops.pop();
                }
                ops.push(s[i]);
                ++i;
            }
        }
        
        while(!ops.empty())
        {
            int second = nums.top();
            nums.pop();
            int first = nums.top();
            nums.pop();
            nums.push(performOperation(ops.top(), first, second));
            ops.pop();
        }
        
        return nums.top();
    }
};