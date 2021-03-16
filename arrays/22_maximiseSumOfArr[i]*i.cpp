/*
Time Complexity : O(n Log n)


*/

#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(arr[i]*i);
    }
    
    return sum;
}

int main()
{
    int arr[]={3,5,6,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    cout<<maxSum(arr,n)<<endl;
    return 0;
}