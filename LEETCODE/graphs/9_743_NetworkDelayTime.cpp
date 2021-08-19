/*
https://leetcode.com/problems/network-delay-time/submissions/

743_NetworkDelayTime

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        vector<int> dist(N+1, INT_MAX);
        dist[k] = 0;
        
        for(int i=0;i<N;i++)
        {
            for(auto e:times)
            {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != INT_MAX && dist[v]>dist[u]+w)
                {
                    dist[v] = dist[u]+w;
                }
            }
        }
        
        int maxwait = 0;
        
        for(int i=1;i<=N;i++)
        {
            maxwait = max(maxwait,dist[i]);
        }
        return maxwait==INT_MAX?-1:maxwait;
        
    }
};