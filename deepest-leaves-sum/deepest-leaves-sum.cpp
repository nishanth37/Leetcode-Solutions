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
    int maxLvl = 1;
    int sum = 0;
    void dfs(TreeNode* node, int level) {
        // base
        if(node == nullptr) return;
        if(maxLvl < level) {
            maxLvl = level;
            sum = 0;
        }
        if(maxLvl == level) {
            sum += node->val;
        }
        // logic
        if(node->left) dfs(node->left, level+1);
        if(node->right) dfs(node->right, level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root, 1);
        return sum;
    }
};