/*
https://leetcode.com/problems/implement-strstr/

28_Implement_KMP

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 104
haystack and needle consist of only lower-case English characters.

*/


class Solution {
private:
    vector<int> preprocess(string& s) 
    {
        vector<int> kmp(s.length()); 
        
        int i = 1, m = 0;
        kmp[0] = 0;
        
        while (i < s.length()) 
        {
            if (s[i] == s[m]) 
            {
                kmp[i++] = ++m;
            } 
            else if (m > 0) 
            {
                m = kmp[m - 1];
            } 
            else 
            {
                kmp[i++] = 0;
            }
        }
        
        return kmp;
    }
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.length() == 0) 
        {
            return 0;
        }
        
        vector<int> kmp = preprocess(needle);
        
        for (int i = 0, j = 0; i < haystack.length();) 
        {
            if (needle[j] == haystack[i]) 
            { 
                ++i; ++j; 
            }
            if (j == needle.length()) 
            {
                return i - j;
            }
            if (i < haystack.length() && needle[j] != haystack[i]) 
            {
                if (j > 0) 
                {
                    j = kmp[j - 1];
                }
                else
                {
                    ++i;
                }
            }
        }
        return -1;
    }
};