/*
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

1930_UniqueLength_3PalindromicSubsequences

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
*/



class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
        for (int i = 0; i < s.size(); ++i) 
        {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i)
            if (first[i] < last[i])
                res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
        return res;
    }
};





class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<pair<int,int>>indexes(26,{-1,-1});
        
        int i=0;
        
        while(s[i]){
            
            if(indexes[s[i]-'a'].first==-1){
                indexes[s[i]-'a']={i,i};
            }
            else{
                indexes[s[i]-'a'].second=i;
            }
            
            i++;
        }
        
        int count=0;
        int ind=0;
        for(auto ele:indexes){
            
            int start=ele.first;
            int end=ele.second;
            
            set<char>sArr;
            start++;
            
            while(start<end){
                sArr.insert(s[start]);
                start++;
            }
            
            count+=sArr.size();
        }
        
        return count;
        
        
    }
};