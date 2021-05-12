/*
Cutting a Rod | DP-13
Difficulty Level : Medium
Last Updated : 20 Apr, 2021
 
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
*/


#include <iostream>
#include<stdio.h>
#include<limits.h>

using namespace std;

int max(int a, int b) { return (a > b)? a : b;}


int maxPrice(int price[], int n)
{
    int maxVal = INT_MIN;
    if(n<=0)
    {
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        maxVal = max(maxVal,price[i] + maxPrice(price,n-i-1));
    }
    return maxVal;
}

int main() {
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d", maxPrice(arr, size));
    return 0;
}
