/*

https://leetcode.com/problems/unique-binary-search-trees/

96_UniqueBinarySearchTrees

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 19

*/







class Solution {
public:
    int numTrees(int n) {
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i] = dp[i] + dp[i-j]*dp[j-1];
            }
        }
        return dp[n];
    }
};




class Solution {
public:
    int numTrees(int n) {
        long long int a = 1;
        for(int i = n+1; i <= 2*n; i++){
            a *= i;
            a /= (i-n);
        }
        a /= n+1;
        return a;
    }
};