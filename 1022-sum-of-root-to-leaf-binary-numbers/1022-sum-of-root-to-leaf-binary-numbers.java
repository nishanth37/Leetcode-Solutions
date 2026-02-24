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
    int res = 0;

    public void dfs(TreeNode root, int currNum) {
        if (root != null) {
            currNum = (currNum << 1) | root.val;
            if (root.left == null && root.right == null) {
                res += currNum;
            }
            dfs(root.left, currNum);
            dfs(root.right, currNum);
        }
    }
    public int sumRootToLeaf(TreeNode root) {
        dfs(root, 0);
        return res;
    }
}