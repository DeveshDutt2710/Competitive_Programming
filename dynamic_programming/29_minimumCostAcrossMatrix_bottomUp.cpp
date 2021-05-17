/*

https://www.geeksforgeeks.org/min-cost-path-dp-6/

Given a cost matrix cost[][] and a position (m, n) in cost[][],
write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). 
Each cell of the matrix represents a cost to traverse through that cell. 
The total cost of a path to reach (m, n) is the sum of all the
costs on that path (including both source and destination). 
You can only traverse down, right and diagonally lower cells from a given cell
, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed.
You may assume that all costs are positive integers.
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 3
#define M 3

int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int minCost(int arr[N][M], int n, int m)
{
    int t[N][M];
    t[0][0] = arr[0][0];
    
    for(int i = 1;i<=n;i++)
    {
        t[i][0] = t[i-1][0] + arr[i][0];
    }
    
    for(int j = 1;j<=m;j++)
    {
        t[0][j] = t[0][j-1] + arr[0][j];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            t[i][j] = min(t[i][j-1], t[i-1][j], t[i-1][j-1]) + arr[i][j];
        }
    }
    return t[n][m];
}

int main()
{
    int cost[N][M] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << "  " << minCost(cost, 2, 2);
   return 0;
}