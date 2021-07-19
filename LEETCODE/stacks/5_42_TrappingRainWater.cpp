
https://leetcode.com/problems/trapping-rain-water/
42_TrappingRainWater


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0; 
        int res = 0;
        
        stack<int> path;   
        for(int i=0; i<height.size(); i++) {
            while(!path.empty() && height[i] > height[path.top()]) {
                int concaveIdx = path.top();
                path.pop();
                
                if(path.empty()) break; 
                int leftIdx = path.top();
                int concaveWidth = i - leftIdx - 1;
                int rainDepth = min(height[i], height[leftIdx]) - height[concaveIdx];
                res += rainDepth*concaveWidth;
            }
            path.push(i);
        }
        return res;
    }
};