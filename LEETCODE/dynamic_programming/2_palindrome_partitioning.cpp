/*

https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    bool palindrome(string prefix)
    {
        int l=0;
        int r=prefix.size()-1;
        while(l<r)
        {
            if(prefix[l]!=prefix[r])
                return false;
            l++;r--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>&v)
    {
        if(s.size()==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string prefix=s.substr(0,i+1);
            string left=s.substr(i+1);
            if(palindrome(prefix))
            {
                v.push_back(prefix);
                solve(left,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(s,ans,v);
        return ans;
    }
};

