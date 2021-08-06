/*
https://www.geeksforgeeks.org/minimum-time-required-to-transport-all-the-boxes-from-source-to-the-destination-under-the-given-constraints/

Given two arrays, box[] and truck[], 
where box[i] represents the weight of the ith box 
and truck[i] represents the maximum load that the ith truck can carry. 
Now each truck takes 1 hour to transport a box from source to destination 
and another one hour to come back. Now, given that all the boxes are kept at the source, 
the task is to find the minimum time required to transport 
all the boxes from the source to the destination. 

Note that there will always be 
some time in which the boxes can 
be transported and only a single box 
can be carried by truck at any instance of time

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool isPossible(int box[], int truck[], int n, int m, int min_time)
{
    int v1=0, v2=0;
    
    while(v1<m)
    {
        for(int i = 0;i<min_time && truck[v1] >= box[v2] && v2<n;i+=2)
        {
            v2++;
        }
        v1++;
    }
    
    if(v2==n)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int minTime(int box[], int truck[], int n, int m)
{
    sort(box, box+n);
    sort(truck, truck+m);
    
    int min_time = 0;
    
    int l=0;
    int h = 2*n;
    
    while(l<=h)
    {
        int mid = (l+h)/2;
        if(isPossible(box,truck,n,m,mid))
        {
            min_time = mid;
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    return min_time;
}




int main()
{
    int box[] = { 10, 2, 16, 19 };
    int truck[] = { 29, 25 };
 
    int n = sizeof(box) / sizeof(int);
    int m = sizeof(truck) / sizeof(int);
 
    printf("%d", minTime(box, truck, n, m));
 
    return 0;
}