/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

787_CheapestFlightsWithinKStops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<int> v(n), V(n,1e8);
        V[src] = 0;
        
        for(int i =0;i<=k;i++)
        {
            v = V;
            for(auto flight : flights)
            {
                v[flight[1]] = min(v[flight[1]], V[flight[0]]+ flight[2]);
            }
            V = v;
        }
        
        return v[dst]==1e8 ? -1 : v[dst];
        
    }
};