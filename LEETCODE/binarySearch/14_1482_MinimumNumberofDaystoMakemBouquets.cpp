/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

1482_MinimumNumberofDaystoMakemBouquets

Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k > n)
        {
            return -1;
        }
        int start = 1;
        int end = 1e9;
        
        while(start != end)
        {
            int mid = (start+end)/2;
            
            int count=0,bouquets=0;
            
            for(auto i:bloomDay)
            {
                if(i<=mid)
                {
                    count++;
                }
                else
                {
                    count=0;
                }
                
                if(count==k)
                {
                    bouquets++;
                    count=0;
                }
            }
            
            if(bouquets < m)
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
        }
        
        return start;
        
    }
};