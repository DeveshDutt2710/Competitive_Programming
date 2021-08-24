/*

https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

MaximumSumSuchThatNoTwoElementsAreAdjacent
*/


#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    
    for(int i=1;i<n;i++)
    {
        if(incl>excl)
        {
            excl_new=incl;
        }
        else
        {
            excl_new=excl;
        }
        
        incl = excl+arr[i];
        excl = excl_new;
    }
    
    return incl>excl?incl:excl;
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout<<FindMaxSum(arr, arr.size());
}