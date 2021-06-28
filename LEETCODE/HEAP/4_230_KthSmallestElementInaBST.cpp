/*

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

230_KthSmallestElementInaBST

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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
    priority_queue<int> pq;
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
        {
            return 0;
        }
        pq.push(root->val);
        if(pq.size()>k)
        {
            pq.pop();
        }
        if(root->left)
        {
            kthSmallest(root->left,k);
        }
        if(root->right)
        {
            kthSmallest(root->right,k);
        }
        return pq.top();
        
    }
};