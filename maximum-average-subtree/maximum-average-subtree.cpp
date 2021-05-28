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
    double res;
    double maximumAverageSubtree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
    
private:
    struct State {
        int count;
        double avg;
    };
    
    State helper(TreeNode* node) {
        // base case
        if(node == nullptr) return {0,0};
        // logic
        State left = helper(node->left);
        State right = helper(node->right);
        State s;
        s.count = left.count + right.count + 1;
        s.avg = (1.0 * (left.avg*left.count + right.avg*right.count + node->val))/s.count;
        res = max(res, s.avg);
        return s;
    }
};