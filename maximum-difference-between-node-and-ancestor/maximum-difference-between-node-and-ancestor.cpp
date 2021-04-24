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
    int res;
    void dfs(TreeNode* node, int minVal, int maxVal) {
        // base
        if(node == nullptr) {
            return ;
        }
        // logic
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);
        res = max(res, abs(minVal - maxVal));
        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        // edge case
        if(root == nullptr) return 0;
        res = INT_MIN;
        int minVal = root->val;
        int maxVal = root->val;
        dfs(root, minVal, maxVal);
        return res;
    }
};