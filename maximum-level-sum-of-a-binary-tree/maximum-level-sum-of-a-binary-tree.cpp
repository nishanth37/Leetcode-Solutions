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
// BFS using queue
// Time Complexity: O(N) N = #nodes in the binary tree
// Space Complexity: O(N) when tree is skewed, height = N
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // edge case
        if(root == nullptr) return 0;
        int res = 1;
        int maxSum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                sum += curr->val;
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(sum > maxSum) {
                maxSum = sum;
                res = lvl;
            }
            lvl++;
        }
        return res;
    }
};