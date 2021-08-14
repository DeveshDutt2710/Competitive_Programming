/*

1676_LowestCommonAncestorofBinaryTreeIV
Level
Medium

Description
Given the root of a binary tree and an array of TreeNode objects nodes, return the lowest common ancestor (LCA) of all the nodes in nodes. All the nodes will exist in the tree, and all values of the tree’s nodes are unique.

Extending the definition of LCA on Wikipedia: “The lowest common ancestor of n nodes p_1, p_2, …, p_n in a binary tree T is the lowest node that has every p_i as a descendant (where we allow a node to be a descendant of itself) for every valid i”. A descendant of a node x is a node y that is on the path from node x to some leaf node.


*/

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode[] nodes) {
        if (root == null || nodes == null || nodes.length == 0)
            return null;
        Set<TreeNode> set = new HashSet<TreeNode>();
        for (TreeNode node : nodes)
            set.add(node);
        return depthFirstSearch(root, set);
    }

    public TreeNode depthFirstSearch(TreeNode root, Set<TreeNode> set) {
        if (root == null || set.contains(root))
            return root;
        TreeNode left = depthFirstSearch(root.left, set);
        TreeNode right = depthFirstSearch(root.right, set);
        if (left != null && right != null)
            return root;
        if (left != null)
            return left;
        if (right != null)
            return right;
        return null;
    }
}