/*
https://leetcode.com/problems/redundant-connection/

684_RedundantConnection

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 
*/


class Solution {
public:
    vector<int> v;
    int find(int a)
    {
        if(v[a]==-1)
        {
            return a;
        }
        return v[a]=find(v[a]);
    }
    
    void merge(int a, int b)
    {
        int temp1 = find(a);
        int temp2 = find(b);
        
        if(temp1==temp2)
        {
            return;
        }
        v[temp1]=temp2;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        v.resize(n+1,-1);
        vector<int> res(2);
        for(auto edge:edges)
        {
            int temp1 = edge[0];
            int temp2 = edge[1];
            
            if(find(temp1) == find(temp2))
            {
                res = edge;
            }
            else
            {
                merge(temp1, temp2);
            }
        }
        
        return res;
    }
};