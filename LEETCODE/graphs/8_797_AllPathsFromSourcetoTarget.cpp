/*
https://leetcode.com/problems/all-paths-from-source-to-target/


797_AllPathsFromSourcetoTarget

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/


class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& paths, vector<int>& path,int i)
    {
        path.push_back(i);
        if(i == g.size()-1)
        {
            paths.push_back(path);
        }
        else
        {
            for(auto it:g[i])
            {
                dfs(g,paths,path,it);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<int> path;
        vector<vector<int>> paths;
        
        dfs(g,paths,path,0);
        return paths;
        
    }
};