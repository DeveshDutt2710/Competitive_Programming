/*

https://leetcode.com/problems/all-possible-full-binary-trees/
894_AllPossibleFullBinaryTrees

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

 

Example 1:


Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
Example 2:

Input: n = 3
Output: [[0,0,0]]
 

Constraints:

1 <= n <= 20

*/









/*
Basic Idea of Question
A full binary tree is a binary tree where each node has either zero or two children, i.e each node is either a leaf or a full node.
The first thing to notice here is that a full binary tree will always have an odd number of nodes, since the root of the tree is a singular node, and each branch adds either 0 or 2 more nodes.
Thus the initial checking if n is even, will remove the error cases from our solution.
Second, the base case of this problem is when n = 1. Then the only full binary tree (rather the only tree) possible is that of a single root.


Approach
If we consider a particular node, we have two options for that node,

Either the remaining nodes to create is 1, so in that case, we just return the single root as the subtree.
Or we have to create both the children of this root and recurse on the children.
For the recursion, we need the number of nodes to generate for the left and the right subtrees. Since we want all the combinations, we just start at 1 and keep the incrementing the size of the left subtree upto n-1, and the size of the right subtree is automatically fixed to n - left_size. Then we recurse on the children with their specified sizes.

Then for creating the subtrees, for each combination of the leftChoices and rightChoices array elements, we create a new root, and assign the respective nodes as its left and right children. Then we add it to the result array.

At the end, we return the result array, which is the solution of the current subproblem.


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
    vector<TreeNode*> allPossibleFBT(int n) {
	
        if((n&1) == 0)
            return {}; 
        if(n == 1)
            return {new TreeNode()};
		
        vector<TreeNode*>res;
		
        for(int i = 1; i < n-1;i+=2)
        {  
		
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(n-i-1); 
			
            for(auto l : left)
            {
                for(auto r : right)
                {
                    TreeNode* root = new TreeNode(); 
                    root->left = l; 
                    root->right = r; 
                    res.push_back(root);
                }
            }
        }
		
        return res;
        
    } 
};