/*
https://leetcode.com/problems/find-a-peak-element-ii/

1901_FindPeakElementII

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/



class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startColumn = 0, endColumn = mat[0].size()-1;
        int midColumn;
        
        while(startColumn<=endColumn)
        {
            midColumn = startColumn+(endColumn-startColumn)/2;
            
            int maxRow = 0;
            
            for(int i=0;i<mat.size();i++)
            {
                if(mat[i][midColumn] >= mat[maxRow][midColumn])
                {
                    maxRow = i;
                }
            }
            
            bool leftBig = midColumn-1 >= startColumn && mat[maxRow][midColumn] < mat[maxRow][midColumn-1];
            bool rightBig = midColumn+1 <= endColumn && mat[maxRow][midColumn] < mat[maxRow][midColumn+1];
            
            if(!leftBig && !rightBig)
            {
                return vector<int>{maxRow, midColumn};
            }
            
            else if(!rightBig)
            {
                endColumn = midColumn-1;
            }
            else
            {
                startColumn = midColumn+1;
            }
        }
        return {-1,-1};
    }
};