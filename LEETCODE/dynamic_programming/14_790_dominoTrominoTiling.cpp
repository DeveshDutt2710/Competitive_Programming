/*
https://leetcode.com/problems/domino-and-tromino-tiling/

790. Domino and Tromino Tiling

We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X
Given n, how many ways are there to tile a 2 x n board? Return your answer modulo 109 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: n = 3
Output: 5
Explanation: 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY
Note:

n will be in range [1, 1000].

*/


#define ll long long int
#define v vector<ll>
#define mod 1000000007
class Solution {
public:
    int numTilings(int N) {
        ll i, j;
        v dp(N+1);
        dp[0]=dp[1]=1;
        for(i=2; i<=N; i++)
            dp[i]=(i-3>=0 && i-1>=0) ? (2*dp[i-1]+dp[i-3])%mod : (2*dp[i-1])% mod;
        return dp[N];
    }
};