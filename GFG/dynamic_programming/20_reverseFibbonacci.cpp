#include <iostream>
using namespace std;

int reverseFib(int n)
{
    int t[n];
    t[0]=0;
    t[1]=1;
    
    for(int i=2;i<n;i++)
    {
        t[i] = t[i-1]+t[i-2];
    }
    for(int i=n-1;i>=0;i--)
    {
        cout<<t[i]<<" ";
    }
}
int main()
{
    reverseFib(5);
    return 0;
}