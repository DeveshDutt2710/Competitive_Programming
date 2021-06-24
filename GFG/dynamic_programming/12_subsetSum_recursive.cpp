//Given a set of non-negative integers, and a value sum,
//determine if there is a subset of the given set with sum equal to given sum. 

//Complexity Analysis: The above solution may try all subsets of given set in worst case.
//Therefore time complexity of the above solution is exponential.

#include <stdio.h>

bool isSubsetSum(int arr[], int n, int sum)
{
    if(sum==0){
        return true;
    }
    
    if(n==0){
        return false;
    }
    
    if(arr[n-1]>sum){
        return isSubsetSum(arr, n-1, sum);
    }
    
    return isSubsetSum(arr,n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
