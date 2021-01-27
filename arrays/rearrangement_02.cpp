/*
Given an array of elements of length N, 
ranging from 0 to N – 1. All elements may 
not be present in the array. If the element 
is not present then there will be -1 present in the array
Rearrange the array such that A[i] = i and if i is not present,
display -1 at that place.
*/

#include <iostream>
using namespace std;

void fixArray(int A[],int n)
{
    for(int i=0;i<n;i++){
        if(A[i]!=-1 && A[i]!=i){
            int x=A[i];
            
            while(A[x]!=-1 && A[x]!=x){
                int y=A[x];
                
                A[x]=x;
                
                x=y;
            }
            A[x]=x;
            
            if(A[i]!=i){
                A[i]=-1;
            }
        }
    }
}

int main()
{
    int A[] = { -1, -1, 6, 1, 9, 
               3, 2, -1, 4, -1 };
 
    int len = sizeof(A) / sizeof(A[0]);
 
    // Function Call
    fixArray(A, len);
 
    // Print the output
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
}