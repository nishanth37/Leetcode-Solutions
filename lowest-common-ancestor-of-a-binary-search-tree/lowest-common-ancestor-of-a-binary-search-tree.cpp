/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    void recurse(TreeNode* curr, TreeNode* p, TreeNode* q) {
        // base
        if((p->val <= curr->val and curr->val <= q->val) 
          or (q->val <= curr->val and curr->val <= p->val)) {
            res = curr;
            return;
        }
        // logic
        if(p->val > curr->val and q->val > curr->val) {
            recurse(curr->right, p, q);
        }
        else if(p->val < curr->val and q->val < curr->val) {
            recurse(curr->left, p, q);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        recurse(root, p, q);
        return res;
    }
};