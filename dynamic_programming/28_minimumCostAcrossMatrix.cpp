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

int minCost(int arr[N][M], int n, int m, int i, int j)
{
    if(i == n-1 && j == m-1)
    {
        return arr[n-1][m-1];
    }
    else if(i == n-1 && j != m-1)
    {
        return arr[i][j] + minCost(arr,n,m,i,j+1);
    }
    else if(i != n-1 && j == m-1)
    {
        return arr[i][j] + minCost(arr,n,m,i+1,j);
    }
    else
    {
        int right = arr[i][j] + minCost(arr,n,m,i,j+1);
        int down = arr[i][j] + minCost(arr,n,m,i+1,j);
        int diagnol = arr[i][j] + minCost(arr,n,m,i+1,j+1);
        return min(right, down, diagnol);
    }
}

int main()
{
    int cost[N][M] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << "  " << minCost(cost, 3, 3,0,0);
   return 0;
}