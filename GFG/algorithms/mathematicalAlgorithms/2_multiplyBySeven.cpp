/*
Time Complexity: O(1)
Space Complexity: O(1)



*/

#include <bits/stdc++.h>
using namespace std;

long multiplyBySeven(long n)
{
    return ((n<<3)-n);
}

int main()
{
    long n=4;
    cout<<multiplyBySeven(n);
    
    return 0;
}
