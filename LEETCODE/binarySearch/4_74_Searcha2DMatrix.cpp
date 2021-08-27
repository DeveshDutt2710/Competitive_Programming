/*
https://leetcode.com/problems/search-a-2d-matrix/

74_Searcha2DMatrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = m*n-1;
        int mid;
        while(low<high)
        {
            mid = (low+high)/2;
            if(matrix[mid/m][mid%m] <target)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }
        }
        return matrix[low/m][low%m] == target;
        
    }
};