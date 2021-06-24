#include <iostream>
using namespace std;

int fib(int n)
{
    int a=0;
    int b=1;
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<a<<" ";
        }
        if(i==1)
        {
            cout<<b<<" ";
        }
        else
        {
            b=b+a;
            a=b-a;
            cout<<b<<" ";
        }
    }
}
    
int main()
{
    fib(9);
    return 0;
}