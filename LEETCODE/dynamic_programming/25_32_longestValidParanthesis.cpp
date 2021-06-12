/*

https://leetcode.com/problems/longest-valid-parentheses/

32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

class Solution {
public:
    int longestValidParentheses(string str) {
        int left=0,right=0,max_length=0;
        for(int i=0;i<str.length();i++){
           if(str[i]=='('){
               left++;
           }
           else{
               right++;
           }
            if(right==left){
                max_length=max(max_length,2*right);
            }
            else if(right>=left){
                right=0;
                left=0;
            }
       }
        left=0,right=0;
         for(int i=str.length()-1;i>=0;i--){
           if(str[i]=='('){
               left++;
           }
           else{
               right++;
           }
            if(right==left){
                max_length=max(max_length,2*right);
            }
            else if(right<=left){
                right=0;
                left=0;
            }
       }
        return max_length;
    }
};







class Solution {
public:
    int longestValidParentheses(string s) {
       int maxlength=0;
       vector<int> dp(s.length(),0);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(s[i]=='(')
                    dp[i]=(i>=2 ? dp[i-2] : 0)+2;
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(')
                    dp[i]=dp[i-1]+((i-dp[i-1])>=2 ? dp[i-dp[i-1]-2] :0)+2;
            }
            maxlength=max(maxlength,dp[i]);
        }
        return maxlength;
    }
};





class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stck;
        stck.push(-1);
        int res=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(') stck.push(i);
            
            else{
                if(!stck.empty())stck.pop();
                
                if(!stck.empty()){
                    res=max(res,i-stck.top());
                }
                else stck.push(i);
            }
        }
        
        return res;
    }
};