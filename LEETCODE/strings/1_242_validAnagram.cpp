/*

https://leetcode.com/problems/valid-anagram/submissions/

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        int arr_s[n], arr_t[m];
        
        if(n != m)
        {
            return false;
        }
        
        for(int i=0; i<n; i++)
        {
            arr_s[i] = s[i]-'0';
            arr_t[i] = t[i]-'0';
        }
        
        sort(arr_s,arr_s + n);
        sort(arr_t,arr_t + m);
        
        for(int i=0; i<n; i++)
        {
            if(arr_s[i] != arr_t[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};