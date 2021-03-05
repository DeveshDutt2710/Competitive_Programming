#include <iostream>
using namespace std;

int setBitNumber(int n)
{
    if(n==0)
    {
        return 0;
    }
    
    int msb=0;
    n=n/2;
    
    while(n!=0)
    {
        n=n/2;
        msb++;
    }
    
    return (1<<msb);
}

int main()
{
    int n=52;
    cout<<setBitNumber(n);
    return 0;
}