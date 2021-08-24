/*
https://leetcode.com/problems/count-submatrices-with-all-ones/

1504_CountSubmatricesWithAllOnes

Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.
*/



class Solution {
public:
    int helper(vector<vector<int>>& mat, int a, int b)
    {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        int bound = m;
        
        for(int i=a;i<n;i++)
        {
            for(int j=b;j<bound;j++)
            {
                if(mat[i][j])
                {
                    count++;
                }
                else
                {
                    bound = j;
                }
            }
        }
        return count;
        
    }
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        int count = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(mat[i][j])
                {
                    count += helper(mat,i,j);
                }
            }
        }
        return count;
    }
};





class Solution {
public:
    int helper(vector<int>& h)
    {
        int length=0;
        int count =0;
        
        for(int i=0;i<h.size();i++)
        {
            length = !h[i] ? 0 : length+1;
            count += length;
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        
        for(int top = 0;top < mat.size();top++)
        {
            vector<int> H(mat[0].size(),1);
            for(int bottom = top;bottom<mat.size();bottom++)
            {
                for(int k = 0;k<mat[0].size();k++)
                {
                    H[k] &= mat[bottom][k] ;
                }
                res+=helper(H);
            }
        }
        return res;
    }
    
};





