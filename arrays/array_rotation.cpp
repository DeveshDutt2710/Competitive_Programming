//time complexity : O(n*d)
//space somplexity : O(1)

#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

void leftRotate(int arr[], int n, int d)
{
    for(int i=1;i<=d;i++)
    {
        leftRotateByOne(arr,n);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    leftRotate(arr, 2, n); 
    printArray(arr, n); 
  
    return 0; 
}
