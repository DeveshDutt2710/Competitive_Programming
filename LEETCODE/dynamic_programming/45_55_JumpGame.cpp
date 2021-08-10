/*
https://leetcode.com/problems/jump-game/

55_JumpGame

You are given an integer array nums. 
You are initially positioned at the array's first index,
and each element in the array represents 
your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i, reach = 0;
        for(i=0;i<n && i<=reach;i++)
        {
            reach = max(i+nums[i],reach);
        }
        return i==n;
        
    }
};


class Solution {
    vector<int> memo;
public:
    bool canJump(vector<int>& nums) {
     
        int n=nums.size();
        vector<int> dp(n,0);
        
        dp[0]=true;
        
        for(int i=1;i<n;i++){
            
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }
                     
             }          
            
        }
        
        return dp[n-1];
        
    }
};


