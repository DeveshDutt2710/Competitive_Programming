#include <stdio.h>
using namespace std;

int count(int S[], int n, int m)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(m<=0 && n>=1)
    {
        return 0;
    }
    
    return count(S,n,m-1) + count(S, n-S[m-1],m);
}

int main()
{
    
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 3));

    return 0;
}