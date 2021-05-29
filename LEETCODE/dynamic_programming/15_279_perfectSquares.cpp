/*

https://leetcode.com/problems/perfect-squares/

279. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104

*/

class Solution {
public:
    int helper(int n, vector<int>& V, vector<int>& dp)
    {
        if(n==0)
        {
            return 0;
        }
        else if(dp[n] != -1)
        {
            return dp[n];
        }
        int steps = 0;
        int min_steps = INT_MAX;
        
        for(int i=0;i<V.size();i++)
        {
            if(n-V[i] >= 0)
            {
                steps = 1 + helper(n-V[i],V,dp);
                if(steps < min_steps)
                {
                    min_steps = steps;
                }
                
            }
            else
            {
                break;
            }
        }
        return dp[n] = min_steps;
    }
    
    int numSquares(int n) {
        vector<int> V;
        vector<int> dp (n+1,-1);
        dp[0] = 0;
        
        for(int i=1;i*i<=n;i++)
        {
            V.push_back(i*i);
        }
        
        return helper(n,V,dp);
    
    }
};