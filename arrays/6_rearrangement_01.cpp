//Rearrange array such that 
//arr[i] >= arr[j] if i is even 
//and arr[i]<=arr[j] if i is odd and j < i


//time complexity : O(nlogn)[because of sort function performing quick sort]
//space complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

void rearrangeArray(int arr[], int n)
{
    int evenPosns=n/2;
    int oddPosns=n-n/2;
    
    int temporaryArray[n];
    sort(arr, arr+n);
    
    int oddIndex=evenPosns;
    int evenIndex=0;
    for(int i=0;i<n;i+=2)
    {
        temporaryArray[i]=arr[oddIndex];
        temporaryArray[i+1]=arr[evenIndex];
        oddIndex++;
        evenIndex++;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<temporaryArray[i]<<" ";
    }
}

int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    rearrangeArray(arr, size); 
    return 0; 
}