/*

Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? 
The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.

https://www.geeksforgeeks.org/coin-change-dp-7/

*/


#include <stdio.h>
using namespace std;

int count(int S[], int n, int m)
{
    int t[n+1][m];
    int x,y;
    
    for (int i = 0; i < m; i++)
    {
        t[0][i] = 1;
    }
        
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            if(i-S[j] >= 0)
            {
                x = t[i-S[j]][j];
            }
            else
            {
                x = 0;
            }
            
            if(j >= 1)
            {
                y = t[i][j-1];
            }
            else
            {
                y = 0;
            }
            
            t[i][j] = x+y;
        }
    }
    return t[n][m-1];
}

int main()
{
    
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, 4, m));

    return 0;
}