class Solution {
public:
    bool solver(string &s, string &p, int a, int b, vector<vector<int>> &dp)
    {
        if(dp[a][b] != -1)
        {
            return dp[a][b];
        }
        
        if(a>=s.length() && b>=p.length())
        {
            return dp[a][b] = true;
        }

        if(b>=p.length())
        {
            return dp[a][b] = false;
        }
        
        bool match = (a<s.length() && (s[a] == p[b] || p[b] == '.'));
        
        if(b<p.length() && p[b+1] == '*')
        {
            return dp[a][b] = solver(s,p,a,b+2,dp) || (match && solver(s,p,a+1,b,dp));
        }
        if(match)
        {
            return dp[a][b] = solver(s,p,a+1,b+1,dp);
        }
        
        return dp[a][b] = false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solver(s,p,0,0,dp);
        
    }
};