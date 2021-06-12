/*
https://leetcode.com/problems/super-egg-drop/

887. Super Egg Drop

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
 

Constraints:

1 <= k <= 100
1 <= n <= 104

*/
// TLE

class Solution {
public:
    int superEggDrop(int k, int n) {
        int min = INT_MAX, results;
        if(k==1)
        {
            return n;
        }
        if(n == 1 || n == 0)
        {
            return n;
        }
        
        for(int i=1;i<=n;i++)
        {
            results = 1 + max(superEggDrop(k-1,i-1), superEggDrop(k,n-i));
            min = min<results?min:results;
        }
        return min;
    }
};


// TLE

class Solution {
public:
    int superEggDrop(int k, int n) {
        int res;
        int memo[n+1][k+1];
        
        for(int i = 1;i<=k;i++)
        {
            memo[1][i] = 1;
            memo[0][i] = 0;
        }
        for(int j=1;j<=n;j++)
        {
            memo[j][1] = j;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                memo[i][j] = INT_MAX;
                for(int x = 1;x<=i;x++)
                {
                    res = 1 + max(memo[x-1][j-1], memo[i-x][j]);
                    if(res < memo[i][j])
                    {
                        memo[i][j] = res;
                    }
                }
                    
            }
        }
        return memo[n][k];
    }
};



class Solution {
public:
    
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     ///Think for base case
        if(K==1) return N;
        
        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
        for(int i=2;i<K+1;i++)
        {
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];
         
    }
};