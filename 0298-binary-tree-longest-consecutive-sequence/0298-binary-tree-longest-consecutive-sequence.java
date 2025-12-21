/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int dfs(TreeNode node, TreeNode parent, int maxVal) {
        if (node == null) return maxVal;
        maxVal = (parent != null && node.val == parent.val + 1) ? maxVal + 1 : 1;
        return Math.max(maxVal, Math.max(dfs(node.left, node, maxVal), dfs(node.right, node, maxVal)));
    }
    public int longestConsecutive(TreeNode root) {
        return dfs(root, null, 0);
    }
}