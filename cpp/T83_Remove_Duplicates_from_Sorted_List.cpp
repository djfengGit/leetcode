/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;
        
        while (fast_ptr != NULL) {
            if (slow_ptr->val != fast_ptr->val && slow_ptr->next != fast_ptr) {
                slow_ptr->next = fast_ptr;
            } else if (slow_ptr->val == fast_ptr->val) {
                fast_ptr = fast_ptr->next;
            } else {
                slow_ptr = fast_ptr;
                fast_ptr = fast_ptr->next;
            }
        }
        if (slow_ptr->next != fast_ptr) {
            slow_ptr->next = NULL;
        }
        
        return head;
    }
};