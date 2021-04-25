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
// Space Complexity: O(H + N) H = height of tree H = N when tree is skewed
// When tree is a complete BT, size of leaves_1, leaves_2 = N/2
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& leaves) {
        // base
        if(root == nullptr) return ;
        
        // logic
        dfs(root->left, leaves);
        dfs(root->right, leaves);
         if(root->left == nullptr and root->right == nullptr)
            leaves.push_back(root->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // edge case
        if(root1 == nullptr and root2 == nullptr) return true;
        vector<int> leaves_1, leaves_2;
        dfs(root1, leaves_1);
        dfs(root2, leaves_2);
        return (leaves_1 == leaves_2);
    }
};