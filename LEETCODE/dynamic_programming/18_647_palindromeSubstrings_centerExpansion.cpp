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
    int countSubstrings(string S) {
        int len = S.length(), ans = 0;
        for (int i = 0; i < len; i++) {
            int j = i - 1, k = i;
            while (k < len - 1 && S[k] == S[k+1]) k++;
            ans += (k - j) * (k - j + 1) / 2, i = k++;
            while (~j && k < len && S[k++] == S[j--]) ans++;
        }
        return ans;
    }
};

int countSubstrings(string s) {
	int n = size(s), cnt = n; // cnt = n, since each single letter is palindrome in itself.
	// For odd length palindromes
	for(int i = 1, l = 0, r = 2; i < n; i++, l = i - 1, r = i + 1)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;                    
	// For even length palindromes
	for(int i = 1, l = 0, r = 1; i < n; i++, l = i - 1, r = i)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;            
	return cnt;
}
