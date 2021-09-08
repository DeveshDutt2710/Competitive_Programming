/*
https://leetcode.com/problems/partition-equal-subset-sum/

416_PartitionEqualSubsetSum

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
*/

class Solution {
public:
    vector<vector<int>>dp;
    int subsetSum(vector<int>& nums, int n, int target)
    {
        if(n<=0)
        {
            return 0;
        }
        if(target==0)
        {
            return 1;
        }
        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }
        
        if(target >= nums[n-1])
        {
            return dp[n][target]=subsetSum(nums,n-1,target) || subsetSum(nums,n-1,target-nums[n-1]);
        }
        return dp[n][target]=subsetSum(nums,n-1,target);
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2 != 0)
        {
            return false;
        }
        sum = sum/2;
        dp.resize(201,vector<int>(sum+1,-1));
        sort(nums.begin(),nums.end());
        
        return subsetSum(nums,nums.size(),sum);
    }
};