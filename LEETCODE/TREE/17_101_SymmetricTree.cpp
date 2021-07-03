/*


https://leetcode.com/problems/symmetric-tree/

101_SymmetricTree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
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
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        bool ans = true;
        queue<TreeNode *> lq, rq;

        lq.push(root->left);
        rq.push(root->right);

        while (!lq.empty() || !rq.empty())
        {
            TreeNode *ln = lq.front();
            TreeNode *rn = rq.front();
            lq.pop();
            rq.pop();

            if (ln == nullptr && rn == nullptr)
                continue;

            if ((ln == nullptr && rn != nullptr) || (rn == nullptr && ln != nullptr))
            {
                ans = false;
                break;
            }

            if (ln->val != rn->val)
            {
                ans = false;
                break;
            }

            lq.push(ln->left);
            lq.push(ln->right);
            rq.push(rn->right);
            rq.push(rn->left);
        }

        if ((lq.empty() && !rq.empty()) || (!lq.empty() && rq.empty()))
            ans = false;

        return ans;
    }
};