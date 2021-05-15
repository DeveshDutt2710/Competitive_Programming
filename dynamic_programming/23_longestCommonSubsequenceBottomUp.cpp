#include <string>
#include <iostream>
using namespace std;


int max(int a, int b)
{
    return (a>b)?a:b;
}

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    
    int t[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                t[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
                t[i][j] = max(t[i][j-1], t[i-1][j]);
            }
        }
    }
    return t[n][m];
}

int main()
{
    string X = "AGGTAB"; 
    string Y = "GXTXAYB"; 
      
    cout<<"Length of LCS is "<< lcs( X, Y) ; 
      
    return 0;
}