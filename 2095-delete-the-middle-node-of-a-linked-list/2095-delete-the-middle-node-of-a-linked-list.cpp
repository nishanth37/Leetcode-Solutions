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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case
        if(head->next == nullptr) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // As the 'fast' reached the end of Linkedlist, the node next to 'slow' node is the middle node of the linked list.
        slow->next = slow->next->next;
        return head;
    }
};