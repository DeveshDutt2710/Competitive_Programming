/*
Time Complexity: O(n^2) time even if the array is sorted
Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int arr[], int n)
{
    int i,j;
    bool swapped;
    
    for(i=0;i<n-1;i++)
    {
        swapped=false;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(&arr[j+1],&arr[j]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
        
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
    bubbleSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
  
