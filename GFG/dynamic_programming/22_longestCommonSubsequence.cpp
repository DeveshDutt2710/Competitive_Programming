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
    
    if(n==0||m==0)
    {
        return 0;
    }
    
    if(s1[0] == s2[0])
    {
        return 1 + lcs(s1.substr(1), s2.substr(1));
    }
    else
    {
        
        return max(lcs(s1.substr(0), s2.substr(1)), lcs(s1.substr(1), s2.substr(0)));
    }
}

int main()
{
    string X = "AGGTAB"; 
    string Y = "GXTXAYB"; 
      
    cout<<"Length of LCS is "<< lcs( X, Y) ; 
      
    return 0;
}