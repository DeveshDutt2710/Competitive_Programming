/*

https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/

Given 3 strings of all having length < 100,
the task is to find the longest common sub-sequence in all three given sequences.

*/

#include <bits/stdc++.h>
using namespace std;

int lcsThreeStrings(string X, string Y, string Z, int m, int n, int o)
{
    int L[m+1][n+1][o+1];
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=o;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    L[i][j][k] = 0;
                }
                else if(X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                {
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
                }
                else
                {
                    L[i][j][k] = max(max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]);
                }
            }
        }
    }
    
    return L[m][n][o];
}

int main()
{
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";
 
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
 
    cout << "Length of LCS is " << lcsThreeStrings(X, Y,
                                    Z, m, n, o);
 
    return 0;
}