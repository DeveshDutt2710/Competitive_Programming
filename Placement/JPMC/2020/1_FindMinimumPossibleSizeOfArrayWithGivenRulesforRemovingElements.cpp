/*

https://www.geeksforgeeks.org/find-minimum-possible-size-of-array-with-given-rules-for-removal/

FindMinimumPossibleSizeOfArrayWithGivenRulesforRemovingElements
Difficulty Level : Hard
Last Updated : 05 Jul, 2021
Given an array of numbers and a constant k, minimize size of array with following rules for removing elements. 

Exactly three elements can be removed at one go.
The removed three elements must be adjacent in array, i.e., arr[i], arr[i+1], arr[i+2]. And the second element must be k greater than first and third element must be k greater than second, i.e., arr[i+1] – arr[i] = k and arr[i+2]-arr[i+1] = k.
Example: 

Input: arr[] = {2, 3, 4, 5, 6, 4}, k = 1
Output: 0
We can actually remove all elements. 
First remove 4, 5, 6 => We get {2, 3, 4}
Now remove 2, 3, 4   => We get empty array {}

Input:  arr[] = {2, 3, 4, 7, 6, 4}, k = 1
Output: 3
We can only remove 2 3 4

*/




#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int DP[MAX][MAX];
int calcMinSize(int arr[], int start, int end, int k){
   if (DP[start][end] != -1)
      return DP[start][end];
   if ( (end-start + 1) < 3)
      return end-start +1;
   int minSize = 1 + calcMinSize(arr, start+1, end, k);
   for (int i = start+1; i<=end-1; i++){
      for (int j = i+1; j <= end; j++ ){
         if (arr[i] == (arr[start] + k) && arr[j] == (arr[start] +
            2*k) && calcMinSize(arr, start+1, i-1, k) == 0 && calcMinSize(arr, i+1, j- 1, k) == 0) {
            minSize = min(minSize, calcMinSize(arr, j+1, end, k));
         }
      }
   }
   return (DP[start][end] = minSize);
}
int main() {
   int arr[] = {4, 6, 8, 4, 1, 5 };
   int n = sizeof(arr)/sizeof(arr[0]);
   int k = 2;
   memset(DP, -1, sizeof(DP));
   cout<<"The minimum possible size of the array after removal is "<<calcMinSize(arr, 0, n-1, k);
   return 0;