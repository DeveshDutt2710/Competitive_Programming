/*
https://leetcode.com/problems/maximum-compatibility-score-sum/

1947_MaximumCompatibilityScoreSum

There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).

Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.
*/


class Solution {
    public:
    int cal(int i,int j,vector<vector<int>>& arr1,vector<vector<int>>& arr2){
        int cnt=0;
        for(int k=0;k<arr1[0].size();k++){
            if(arr1[i][k]==arr2[j][k]){
                cnt++;
            }
        }
        return cnt;
    }
    
    int helper(int i,int m,vector<vector<int>>& arr1,vector<vector<int>>& arr2,vector<bool>& vis){
        if(i==m){
            return 0;
        }
        int ans = 0;
        for(int j=0;j<m;j++){
            if(!vis[j]){
                vis[j]=1;
                ans = max(ans,cal(i,j,arr1,arr2) + helper(i+1,m,arr1,arr2,vis));
                vis[j]=0;
            }
        }
        return ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> vis(m,0); // To keep track of which mentor is already paired up
        return helper(0,m,students,mentors,vis);
    }
};