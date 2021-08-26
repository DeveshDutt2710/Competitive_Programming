/*
https://leetcode.com/problems/number-of-different-subsequences-gcds/

1819_NumberofDifferentSubsequencesGCDs

You are given an array nums that consists of positive integers.

The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in the sequence evenly.

For example, the GCD of the sequence [4,6,16] is 2.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
Return the number of different GCDs among all non-empty subsequences of nums.




*/


class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int curr_max = INT_MIN, ret = 0, n = nums.size();
        int present[200001] = {0};
        for(int i=0; i<n; i++)
        {
            curr_max = max(curr_max, nums[i]);
            present[nums[i]]=1;
        }
        for(int i=1; i<=curr_max; i++)
        {
            int curr_gcd = 0;
            for(int j=i; j<=curr_max; j+=i)
            {
                if(present[j]==1)
                    curr_gcd = gcd(curr_gcd, j);
                if(curr_gcd==i)
                {
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};


// Since numbers are between [1, 200000], we know that max GCD that we can get is 200000. Now, if we could frame problem as checking if we could form GCD as i for all i in range [1, 200000], then we can easily find the count of all possible GCDs.

// In order to check if we could form some number i, we first find out all numbers that have a factor of i in them (because those are the only numbers that could ever form a GCD as i). Now, in order for some subsequence of them to form i as GCD, it must be true that these numbers (with factor of i in them) must all have a combined GCD of i as well.

// If numbers with factor of i in them form a GCD > i then we can never form i with any subsequence of them.