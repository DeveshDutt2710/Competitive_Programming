/*
https://leetcode.com/problems/continuous-subarray-sum/

523_ContinuousSubarraySum

Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     
	int prefSum = 0;
	unordered_map<int, int> mp;
	for(int i=0; i<nums.size(); i++)
	{
		prefSum += nums[i];
		prefSum %= k;

		if(prefSum == 0 && i) 
            return true;

		if(mp.find(prefSum) != mp.end())
		{
			if(i - mp[prefSum] > 1) 
                return true;
		}
		else mp[prefSum] = i;
	}

	return false;
}
};