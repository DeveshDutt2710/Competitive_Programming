#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n)
{
    int t[n+1];
    
    for(int i=0;i<=n;i++)
    {
        if(i<=2)
        {
            t[i] = i;
        }
        else
        {
            t[i] = t[i-1] + (i-1)*t[i-2];
        }
    }
    return t[n];
}
int main()
{
    cout<<friendsPairing(4);
    
    return 0;
}