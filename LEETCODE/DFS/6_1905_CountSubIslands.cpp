/*
https://leetcode.com/problems/count-sub-islands/

1905_CountSubIslands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.
*/


class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int &res) {
        int m = grid1.size(), n = grid1[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return;
        if(grid1[x][y] == 0 && grid2[x][y] == 1) {
            res = false;
        }
        if(grid2[x][y] == 0) return;
        grid2[x][y] = 0;
        dfs(grid1, grid2, x + 1, y, res);
        dfs(grid1, grid2, x, y + 1, res);
        dfs(grid1, grid2, x - 1, y, res);
        dfs(grid1, grid2, x, y - 1, res);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    int res = true;
                    dfs(grid1, grid2, i, j, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};