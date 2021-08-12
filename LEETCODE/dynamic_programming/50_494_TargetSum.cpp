/*

494_TargetSum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/


class Solution {
public:
    
    int solve(vector<int>& nums,int sum,int t,int ind){
        int n=nums.size();
        if(n==ind){
            if(sum==t) return 1;
            return 0;
        }
        int res=0;
        res+=solve(nums,sum+nums[ind],t,ind+1);

        res+=solve(nums,sum-nums[ind],t,ind+1);
        return res;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int t) {
        return solve(nums,0,t,0);
    }
};