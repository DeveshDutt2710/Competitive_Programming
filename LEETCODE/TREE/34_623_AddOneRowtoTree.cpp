/*
https://leetcode.com/problems/add-one-row-to-tree/

623_AddOneRowtoTree
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
    TreeNode* addOneRow(TreeNode* root, int v, int d, bool isLeft = true) {
        if ( d == 1 )
        {
            TreeNode *left = isLeft? root : NULL, *right = isLeft? NULL : root;
            return new TreeNode(v, left, right);
        }
            
        if ( root )
        {
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1, false);
        }
            
        return root;
    }
};
 
 
 
class Solution {
public:
    void helper(TreeNode* node, int depth, int v, int d){
        if(!node)return;
        if(depth<d-1){
            helper(node->left,depth+1,v,d);
            helper(node->right,depth+1,v,d);
        }
        else{
            TreeNode *t=node;
            TreeNode *a=new TreeNode(v);
            a->left=t->left;
            TreeNode *b=new TreeNode(v);
            b->right=t->right;
            t->left=a;
            t->right=b;
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode * nn=new TreeNode(v);
            nn->left=root;
            return nn;
        }
        helper(root,1,v,d);
        return root;
    }
};




