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