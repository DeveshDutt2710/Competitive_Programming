/*
https://leetcode.com/problems/pacific-atlantic-water-flow/

417_PacificAtlanticWaterFlow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/


class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int i, int j)
    {
        int n = h.size();
        int m = h[0].size();
        
        visited[i][j]=true;
        
        if(i+1<n && !visited[i+1][j] && h[i+1][j]>=h[i][j])
        {
            dfs(h,visited,i+1,j);
        }
        if(i-1>=0 && !visited[i-1][j] && h[i-1][j]>=h[i][j])
        {
            dfs(h,visited,i-1,j);
        }
        if(j+1<m && !visited[i][j+1] && h[i][j+1]>=h[i][j])
        {
            dfs(h,visited,i,j+1);
        }
        if(j-1>=0 && !visited[i][j-1] && h[i][j-1]>=h[i][j])
        {
            dfs(h,visited,i,j-1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        int n = h.size();
        int m = h[0].size();
        
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        
        
        for(int i=0;i<n;i++)
        {
            dfs(h,pacific,i,0);
            dfs(h,atlantic,i,m-1);
        }
        
        for(int j=0;j<m;j++)
        {
            dfs(h,pacific,0,j);
            dfs(h,atlantic,n-1,j);
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};