/*

45_JumpGameII

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
*/


class Solution {
public:
    int jump(vector<int>& nums) 
    {
	    vector<int> dp(size(nums), 1001); 
	    return solve(nums, dp, 0);
    }

    int solve(vector<int>& nums, vector<int>& dp, int pos) 
    {
        if(pos >= size(nums) - 1)
        {
            return 0;   
        }
        if(dp[pos] != 1001) 
        {
            return dp[pos];   
        }

        for(int j = 1; j <= nums[pos]; j++)
        {
            dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        
        }
        return dp[pos];
    }
};


int jump(vector<int>& nums) {
	int n = size(nums);
	vector<int> dp(n, 1001);
	dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
	// same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
	for(int i = n - 2; i >= 0; i--) 
		for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++) 
			dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
	return dp[0];
}




int jump(vector<int>& nums) {
	int n = size(nums), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;
	while(lastJumpedPos < n - 1) {  // loop till last jump hasn't taken us till the end
		maxReachable = max(maxReachable, i + nums[i]);  // furthest index reachable on the next level from current level
		if(i == lastJumpedPos) {			  // current level has been iterated & maxReachable position on next level has been finalised
			lastJumpedPos = maxReachable;     // so just move to that maxReachable position
			jumps++;                          // and increment the level
	// NOTE: jump^ only gets updated after we iterate all possible jumps from previous level
	//       This ensures jumps will only store minimum jump required to reach lastJumpedPos
		}            
		i++;
	}
	return jumps;
}