/*

https://leetcode.com/problems/longest-palindromic-subsequence/
516_LongestPalindromicSubsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/


//RECURSIVE

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2,int m,int n) {
        if(m==0 || n==0){
            return 0;
        }
        if(text1[m-1]==text2[n-1]){
            return 1+longestCommonSubsequence(text1,text2,m-1,n-1);
        }else{
            return max(longestCommonSubsequence(text1,text2,m-1,n),longestCommonSubsequence(text1,text2,m,n-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string w=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,w,m,m);
    }
};


//MEMO

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2,int m,int n,int memo[][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
    int longestPalindromeSubseq(string s) {
        int m=s.size();
        string w=s;
        reverse(s.begin(),s.end());
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return longestCommonSubsequence(s,w,m,m,memo);
    }
};


//BOTTOM UP

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string w=s;
        reverse(s.begin(),s.end());
        int m=s.size();
        int dp[m+1][m+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<m+1;j++){
               if(s[i-1]==w[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[m][m];
    }
};