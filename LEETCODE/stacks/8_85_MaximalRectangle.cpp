/*
https://leetcode.com/problems/maximal-rectangle/

85_MaximalRectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0)
            return 0;
        
        stack<int> S;
        
        int L[n];
        int R[n];
        
        for(int i=0; i<n; i++) 
        {
            while(!S.empty() && heights[S.top()] >= heights[i]) 
                S.pop();
            
            L[i] = S.empty() ? -1 : S.top();
            S.push(i);
        }
        
        while(!S.empty()) S.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!S.empty() && heights[S.top()] >= heights[i])
                S.pop();
            
            R[i] = S.empty() ? n : S.top();
            S.push(i);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            ans = max(ans, (R[i]-L[i]-1) * heights[i]);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int n = matrix.size();
        
        
        if(n==0)
        {
            return 0;
        }
        
        int m = matrix[0].size();
        
        vector<int> heights(m,0);
        int maxArea = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    heights[j]=0;
                }
                else
                {
                    heights[j]++;
                }
            }
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};