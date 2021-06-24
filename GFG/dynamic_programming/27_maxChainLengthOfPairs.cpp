/*
https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

You are given n pairs of numbers. 
In every pair, the first number is always smaller than the second number.
A pair (c, d) can follow another pair (a, b) if b < c.
Chain of pairs can be formed in this fashion. 
Find the longest chain which can be formed from a given set of pairs. 

*/


#include <bits/stdc++.h>
using namespace std;

struct Pair{
    int a;
    int b;
};

int maxChainLength(Pair arr[], int n)
{
    int i,j,max = 0;
    int *max_chain_length = new int[sizeof(int)*n];
    
    for(i=0;i<n;i++)
    {
        max_chain_length[i] = 1;
    }
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i].a > arr[j].b &&
              max_chain_length[i] < max_chain_length[j]+1)
              {
                  max_chain_length[i]=max_chain_length[j]+1;
              }
        }
    }
    
    for(i=1;i<n;i++)
    {
        if(max<max_chain_length[i])
        {
            max=max_chain_length[i];
        }
    }
    
    return max;
}
int main()
{
    Pair arr[] = { {5, 24}, {15, 25},
                        {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of maximum size chain is "
                  << maxChainLength( arr, n );
    return 0;
}
