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
// Time Complexity: O(N^2) N = #nodes in tree
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // edge case
        if(root == nullptr) return {};
        vector<vector<int>> res;
        // space: O(N) when it is a complete binary tree, there are N/2 leaf nodes
        queue<TreeNode*> q; 
        q.push(root);
        int lvl = 1;
        while(!q.empty()) { // worst-case time; O(N)
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(lvl%2 == 0)
                reverse(temp.begin(), temp.end()); // worst-case time: O(N)
            lvl++;
            res.push_back(temp);
        }
        return res;
    }
};