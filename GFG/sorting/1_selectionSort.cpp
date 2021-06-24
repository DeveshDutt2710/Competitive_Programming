/*
Time Complexity: O(n*n) as there are two nested loops.

Auxiliary Space: O(1)

The good thing about selection sort is 
it never makes more than O(n) swaps and can be useful
when memory write is a costly operation.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int arr[], int n)
{
    int i,j, min_idx;
    
    for(i=0;i<n;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        swap(&arr[i],&arr[min_idx]);
    }
}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 

int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
  
