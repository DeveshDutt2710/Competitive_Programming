/*Thus the idea is to keep following unused edges and removing them until we get stuck. Once we get stuck, we backtrack to the nearest vertex in our current path that has unused edges, and we repeat the process until all the edges have been used. We can use another container to maintain the final path.

https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/

*/



/*
https://leetcode.com/problems/reconstruct-itinerary/

332_ReconstructItinerary

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

 

Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 

Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
*/


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> g;
        vector<string> ans;
        for(auto ticket : tickets)
        {
            g[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push("JFK");
        while(!s.empty())
        {
            string temp = s.top();
            if(g[temp].size() == 0)
            {
                ans.push_back(temp);
                s.pop();
            }
            else
            {
                auto dst = g[temp].begin();
                s.push(*dst);
                g[temp].erase(dst);
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
