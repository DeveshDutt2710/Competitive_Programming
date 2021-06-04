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
    int calculate(string s) {
        vector<int> vt;
        
        int num=0;
        char sign='+';
        for(int i=0;i<=s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||i==s.length()){
                if(sign=='+'){
                    vt.push_back(num);
                    num=0;
                }else if(sign=='-'){
                    vt.push_back(-1*num);
                    num=0;
                }else if(sign=='/'){
                    vt[vt.size()-1]=vt.back()/num;
                    num=0;
                }else if(sign=='*'){
                    vt[vt.size()-1]=vt.back()*num;
                    num=0;
                }
                
                if(i!=s.length()){
                 sign=s[i];   
                }
            }
        }
        
        int result=0;
        for(int i=0;i<vt.size();i++){
            result+=vt[i];
        }
        
        return result;
    }
};