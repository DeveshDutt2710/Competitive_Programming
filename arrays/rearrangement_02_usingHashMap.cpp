/*
Given an array of elements of length N, 
ranging from 0 to N – 1. All elements may 
not be present in the array. If the element 
is not present then there will be -1 present in the array
Rearrange the array such that A[i] = i and if i is not present,
display -1 at that place.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

void fixArray(int arr[],int n)
{
    unordered_map<int,int> hmap;
    
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){
            hmap[arr[i]]=1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(hmap.find(i)!=hmap.end()){
            arr[i]=i;
        }
        else{
            arr[i]=-1;
        }
    }
}
