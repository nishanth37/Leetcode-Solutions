/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildBST(ListNode* start, ListNode* end) {
        // base case
        if(start == end) return nullptr;
        
        // logic
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast != end and fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildBST(start, slow);
        root->right = buildBST(slow->next, end);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // edge case
        if(head == nullptr) return nullptr;
        return buildBST(head, nullptr);
    }
};