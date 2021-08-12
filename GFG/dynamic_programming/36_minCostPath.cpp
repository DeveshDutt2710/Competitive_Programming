/*

https://www.geeksforgeeks.org/min-cost-path-dp-6/


*/


int minCost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] +
         min(minCost(cost, m - 1, n - 1),
             minCost(cost, m - 1, n),
             minCost(cost, m, n - 1));
}