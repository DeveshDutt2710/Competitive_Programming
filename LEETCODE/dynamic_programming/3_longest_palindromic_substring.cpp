/*
https://leetcode.com/problems/longest-palindromic-substring/

time limit exceed

*/



class Solution {
public:
    
    bool palindrome(string word)
    {
        int l = 0;
        int r = word.size()-1;
        while(l<r)
        {
            if(word[l] != word[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        
        for(int i=s.size(); i>0; i--)
        {
            for(int j=0; j<=(s.size()-i); j++)
            {
                if(palindrome(s.substr(j,i)))
                {
                    return s.substr(j,i);
                }
            }
        }
        return "no palindrome found";
    }
};