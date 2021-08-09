/*


132_PalindromePartitioningII

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
*/





class Solution {
public:
    vector<vector<int>> dp;
    bool ispalindrome(string& str,int i,int j){
        if(i==j)
            return true;
        if(i>j)
            return true;
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
                
        }
        return true;
    }
    int palpar(string& str,int i,int j){
        if(i>=j)
            return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        else if(ispalindrome(str,i,j)){
            dp[i][j] = 0;
            return 0;
        }

        int mn = INT_MAX;    
        for(int k{i} ; k<=j-1 ; k++){
            int left{0};
            int right{0};
            if(ispalindrome(str,i,k)){
                right = palpar(str,k+1,j);
            }
            else{
                dp[i][k] = 0;
                continue;
            }
            
            int temp = right+1;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int minCut(string str) {
        int n = str.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return palpar(str,0,n-1);
    }
    
};
















class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string &s,int i, int j)
    {
        if(i>=j)
        {
            return true;
        }
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int palindromePartitioning(string &s, int i, int j)
    {
        int res = INT_MAX;
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(isPalindrome(s,i,j))
        {
            return dp[i][j] = 0;
        }
        
        for(int k=i; k<=j-1;k++)
        {
            int temp = palindromePartitioning(s,i,k) + 1 + palindromePartitioning(s,k+1,j);
            if(temp < res)
            {
                res = temp;
            }
        }
        
        return dp[i][j] = res;
    }
    int minCut(string s) {
        int n = s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return palindromePartitioning(s,0,n-1);
    }
};