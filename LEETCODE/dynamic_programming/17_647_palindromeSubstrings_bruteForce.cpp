/*

https://leetcode.com/problems/palindromic-substrings/

647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    int isPalindrome(string s)
    {
        int start = 0;
        int end = s.size()-1;
        while(start <= end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
                
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(isPalindrome(s.substr(i,j)))
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};