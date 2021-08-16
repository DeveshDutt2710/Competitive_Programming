/*

95_UniqueBinarySearchTreesII

Given an integer n, return all the 
structurally unique BST's (binary search trees), which has exactly n 
nodes of unique values from 1 to n. Return the answer in any order.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n, int base = 0) {
		
        vector<TreeNode*> ans;
        if (n == 0) {
            return { nullptr };
        }
		
        for (int i = 1; i <= n; i++) {
            for (auto left : generateTrees(i - 1, base)) 
            {
                for (auto right : generateTrees(n - i, i + base)) 
                {
                    ans.push_back(new TreeNode(i + base, left, right));
                }
            }
        }
        return ans;
    }
};