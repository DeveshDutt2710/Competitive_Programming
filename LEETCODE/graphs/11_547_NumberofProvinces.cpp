/*


547_NumberofProvinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


*/



class Solution {
public:
    vector<int> v;
    
    int find(int i)
    {
        if(v[i]==-1)
        {
            return i;
        }
        return v[i]=find(v[i]);
    }
    
    void merge(int a, int b)
    {
        int temp1 = find(a);
        int temp2 = find(b);
        
        if(temp1==temp2)
        {
            return;
        }
        v[temp1] = temp2;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        v.resize(n,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    merge(i,j);
                }
            }
        }
        int c = 0;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
            {
                c++;
            }
        }
        return c;
    }
};