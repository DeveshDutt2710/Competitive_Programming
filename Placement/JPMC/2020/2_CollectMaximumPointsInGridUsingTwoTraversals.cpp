/*
https://www.geeksforgeeks.org/collect-maximum-points-in-a-grid-using-two-traversals/

CollectMaximumPointsInGridUsingTwoTraversals

Given a matrix where every cell represents points. 
How to collect maximum points using two traversals under following conditions?
Let the dimensions of given grid be R x C.
1) The first traversal starts from top left corner, 
    i.e., (0, 0) and should reach left bottom corner, i.e., (R-1, 0). 
    The second traversal starts from top right corner, i.e., (0, C-1) 
    and should reach bottom right corner, i.e., (R-1, C-1)/
    
2) From a point (i, j), we can move to (i+1, j+1) or (i+1, j-1) or (i+1, j)

3) A traversal gets all points of a particular cell through which it passes. 
    If one traversal has already collected points of a cell, 
    then the other traversal gets no points if goes through that cell again.
 

Input :
    int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };

     Output: 73

Explanation :

First traversal collects total points of value 3 + 2 + 20 + 1 + 1 = 27

Second traversal collects total points of value 2 + 4 + 10 + 20 + 10 = 46.
Total Points collected = 27 + 46 = 73

*/





#include<bits/stdc++.h>
using namespace std;
#define R 5
#define C 4
 

bool isValid(int x, int y1, int y2)
{
    return (x >= 0 && x < R && y1 >=0 &&
            y1 < C && y2 >=0 && y2 < C);
}
 
int getMaxUtil(int arr[R][C], int mem[R][C][C], int x, int y1, int y2)
{
    
    if (!isValid(x, y1, y2)) return INT_MIN;
 
    if (x == R-1 && y1 == 0 && y2 == C-1)
       return (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2];
 
 
    if (x == R-1) return INT_MIN;
    
    if (mem[x][y1][y2] != -1) return mem[x][y1][y2];
    int ans = INT_MIN;
    int temp = (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2];
 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2-1));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2+1));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2));
 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2-1));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2+1));
 
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2-1));
    ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2+1));
 
    return (mem[x][y1][y2] = ans);
}

int geMaxCollection(int arr[R][C])
{

    int mem[R][C][C];
    memset(mem, -1, sizeof(mem));
 
    return getMaxUtil(arr, mem, 0, 0, C-1);
}
 
int main()
{
    int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };
    cout << "Maximum collection is " << geMaxCollection(arr);
    return 0;
}
