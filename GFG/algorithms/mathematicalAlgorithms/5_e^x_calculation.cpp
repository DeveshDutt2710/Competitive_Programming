/*
e^x = 1 + x/1! + x^2/2! + x^3/3! + ...... 
How to efficiently calculate the sum of above series?
The series can be re-written as

e^x = 1 + (x/1) (1 + (x/2) (1 + (x/3) (........) ) )

*/

#include <bits/stdc++.h>
using namespace std;

float exponential(int n, float x)
{
    float sum=1.0f;
    
    for(int i=n-1;i>0;--i)
    {
        sum=1+x*sum/i;
    }
    
    return sum;
}

int main()
{
    int n=10;
    float x=1.0f;
    cout<<"e^x = "<<fixed<<setprecision(5)<<exponential(n,x);
    
    return 0;
}