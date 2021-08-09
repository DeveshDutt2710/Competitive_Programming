/*

410_SplitArrayLargestSum

Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

*/





class Solution {
public:
    
    int dp[1001][51];
    
    int ff(vector<int>& nums, int m, int i) {
        
        if (i == nums.size() && m == 0) return 0;
        if (i == nums.size() || m == 0) return INT_MAX;
        if (dp[i][m] != -1) return dp[i][m];
        
        int final_ans = INT_MAX;
        
        for (int idx=i; idx < nums.size(); idx++) {
            int res = nums[idx] - ((i - 1 >= 0) ? nums[i - 1] : 0);
            int t = ff(nums, m - 1, idx + 1);
            final_ans = min(final_ans, max(res, t));
        }
        
        return dp[i][m] = final_ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        memset(dp, -1, sizeof dp);
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == INT_MAX) return INT_MAX;
            nums[i] += (i - 1 >= 0) ? nums[i - 1] : 0;
        }
        return ff(nums, m, 0);
    }
};





class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefixSum;
    int solve(vector<int> &num,int m, int i, int j)
    {
        if(i>j)
        {
           return 0; 
        }
        
        if(i==j)
        {
            return num[i];
        }
        
        if(m==0)
        {
            if(i==0)
            {
                return prefixSum[j];
            }
            else
            {
                return prefixSum[j]-prefixSum[i-1];
            }
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int res = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp1=0,temp2=0;
            if(i==0)
            {
                temp1 = prefixSum[k];
            }
            else
            {
                temp1 = prefixSum[k]-prefixSum[i-1];
            }
            temp2 = solve(num,m-1,k+1,j);
            int temp = max(temp1,temp2);
            res = min(res,temp);
        }
        return dp[i][j] = res;
            
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(n+1,-1));
        prefixSum.resize(n,0);
        
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        return solve(nums,m-1,0,n-1);
    }
};