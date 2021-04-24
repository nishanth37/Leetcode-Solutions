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
// Using DFS
// Time Complexity: O(N) N = #nodes
// Space Complexity: O(H) H = height of tree...height = N when skewed tree
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* node) {
        // base
        if(node == nullptr) return ;
        // logic
        res.push_back(node->val);
        if(node->left) dfs(node->left);
        if(node->right) dfs(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // edge case
        if(root == nullptr) return {};
        dfs(root);
        return res;
    }
};