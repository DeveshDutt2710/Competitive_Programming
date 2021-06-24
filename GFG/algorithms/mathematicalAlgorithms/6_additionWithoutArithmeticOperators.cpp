#include <bits/stdc++.h>
using namespace std;

int add(int x, int y)
{
    while(y!=0)
    {
        int carry =x&y;
        
        x=x^y;
        y=carry<<1;
    }
    return x;
}

int main()
{
    cout<<add(15,32);
    return 0;
}