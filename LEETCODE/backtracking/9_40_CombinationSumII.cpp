/*

https://leetcode.com/problems/combination-sum-ii/

40_CombinationSumII

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



*/




class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& temp, vector<int>& candidates, int target, int k)
    {
        if(target<0)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(temp);
        }
        for(int i=k;i<candidates.size();i++)
        {
            if(candidates[i]>target)
            {
                return;
            }
            if(i && candidates[i]==candidates[i-1] && i > k)
            {
                continue;
            }
            temp.push_back(candidates[i]);
            helper(temp,candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(temp,candidates,target,0);
        set<vector<int>>pq;
        for(auto i:ans)
        pq.insert(i);
        vector<vector<int>>ans1;
        for(auto i:pq)
        {
            ans1.push_back(i);
        }
        return ans1;
    }
};