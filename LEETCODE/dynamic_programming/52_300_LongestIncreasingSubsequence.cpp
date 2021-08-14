/*

https://leetcode.com/problems/longest-increasing-subsequence/

300LongestIncreasingSubsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array 
by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1,1);
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] && arr[i]<=arr[j])
                {
                    arr[i] = 1+arr[j];
                }
            }
            res = max(res,arr[i]);
        }
        return res;
        
    }
};