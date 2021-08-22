/*
https://leetcode.com/problems/combination-sum/

39_CombinationSum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/



class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& temp, vector<int>& candidates, int target,int k)
    {
        
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i=k;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            helper(temp,candidates,target-candidates[i],i);
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> temp;
        
        helper(temp,candidates,target,0);
        return res;
        
        
    }
};