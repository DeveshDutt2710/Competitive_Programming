/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

*/

class Solution {
public:
    int dp[100001][2][3];    
    
       int recurs(vector<int>& prices,int i,int hold,int tran)
    {   
        if(i>=prices.size()||tran>=2)
        {
                return 0;
        }
        
        if(dp[i][hold][tran]!=-1)
        {
            return dp[i][hold][tran];
        }

        
        if(hold!=0)
        {
            return dp[i][hold][tran]=max(prices[i]+recurs(prices,i+1,0,tran+1),recurs(prices,i+1,hold,tran));
        }
        else
        {
            return dp[i][hold][tran]=max(recurs(prices,i+1,0,tran),recurs(prices,i+1,1,tran)-prices[i]);
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        
        
        for(int i=0;i<prices.size();i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<3;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        
        
        return recurs(prices,0,0,0);

        
    }
};
