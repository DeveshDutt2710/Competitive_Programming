/*
https://leetcode.com/problems/subarray-sum-equals-k/

560_SubarraySumEqualsK

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
*/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int runningSum = 0;
        int count = 0;
        m[0]++;
        for(int i=0;i<nums.size();i++)
        {
            runningSum += nums[i];
            count += m[runningSum - k];
            m[runningSum]++;
        }
        return count;
    }
};