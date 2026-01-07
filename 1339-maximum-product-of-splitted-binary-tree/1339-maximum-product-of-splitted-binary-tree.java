// T.C.: O(n) - each node is visited once - O(n) and iterating the allSums list is also O(n)
// S.C.: O(n) - O(n) for worst-case recursion + O(n) for allSums list size
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
    private List<Integer> allSums = new ArrayList<>();

    private int treeSum(TreeNode node) {
        if (node == null) return 0;
        int leftSum = treeSum(node.left);
        int rightSum = treeSum(node.right);
        int totalSum = leftSum + node.val + rightSum;
        allSums.add(totalSum);
        return totalSum;
    }
    public int maxProduct(TreeNode root) {
        long totalSum = treeSum(root);
        long res = 0;
        for (long sum : allSums) {
            res = Math.max(res, ((totalSum - sum) * sum));
        }
        return (int)(res % 1000000007);
    }
}