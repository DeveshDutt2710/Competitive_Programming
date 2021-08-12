/*

120_Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/


class Solution {
public:
   int minTotalUtil(vector<vector<int>>& triangle, int h, int j) {
        
       if(h == triangle.size()) {
             return 0;
        }  
        
        return triangle[h][j]+min(minTotalUtil(triangle, h+1, j),minTotalUtil(triangle, h+1, j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         
          return minTotalUtil(triangle, 0, 0);
    }
};



class Solution {
public:
   int minTotalUtil(vector<vector<int>>& triangle, int h, int j,vector<vector<int>> &v) {
        if(h == triangle.size()) {
             
            return 0;
        }
         if(v[h][j]!=-1) return v[h][j];  
        
        return v[h][j]=triangle[h][j]+min(minTotalUtil(triangle, h+1, j,v),minTotalUtil(triangle, h+1, j+1,v));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int h=triangle.size(),j;
         j=h;
        vector<vector<int>> v(h,vector<int> (j,-1));
          minSum=minTotalUtil(triangle, 0, 0,v);
        
        cout << minSum << endl;
        return minSum;
        
    }
};