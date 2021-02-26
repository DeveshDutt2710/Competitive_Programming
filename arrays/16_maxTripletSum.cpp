/*
1) brute force
2) sort and give sum of last three

This approach -> maintain max , second max and third max element of an array 
and retrun their sum in the end
*/

#include <bits/stdc++.h>
using namespace std;

int maxTripletSum(int arr[], int n)
{
    int max=INT_MIN,secondMax=INT_MIN,thirdMax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            thirdMax=secondMax;
            secondMax=max;
            max=arr[i];
        }
        else if(arr[i]>secondMax)
        {
            thirdMax=secondMax;
            secondMax=arr[i];
        }
        else if(arr[i]>thirdMax)
        {
            thirdMax=arr[i];
        }
    }
    return max+secondMax+thirdMax;
}

int main() 
{ 
    int arr[] = { 1, 0, 8, 6, 4, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << maxTripletSum(arr, n); 
    return 0; 
} 