/*
Time Complexity: O(n*2)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. 
                And it takes minimum time (Order of n) when elements are already sorted.

Uses: Insertion sort is used when number of elements is small.
        It can also be useful when input array is almost sorted, 
        only few elements are misplaced in complete big array
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i,j,key;
    
    for(i=1;i<n;i++)
    {
        key= arr[i];
        j=i-1;
        while(j>=0 && key<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
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
    insertionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
  
