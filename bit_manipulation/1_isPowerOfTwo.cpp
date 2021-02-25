#include <bits/stdc++.h>
using namespace std;
#define bool int

bool isPowerOfTwo(int x)
{
    return x && (!(x&(x-1)));
}

int main()
{
    isPowerOfTwo(31)?cout<<"Yes\n": cout<<"No\n";
    isPowerOfTwo(64)?cout<<"Yes\n": cout<<"No\n";
    
    return 0;
}