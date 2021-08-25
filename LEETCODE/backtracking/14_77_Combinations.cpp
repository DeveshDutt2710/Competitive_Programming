/*
https://leetcode.com/problems/combinations/

77_Combinations

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.
*/



class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& combination, int begin, int n, int k)
    {
        if(combination.size()==k)
        {
            res.push_back(combination);
            return;
        }
        
        for(int i=begin;i<=n;i++)
        {
            combination.push_back(i);
            solve(res,combination,i+1,n,k);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> res;
        solve(res,combination,1,n,k);
        
        return res;
    }
};