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
    ListNode* partition(ListNode* head, int x) {
        ListNode* front_dummy = new ListNode(0);
        ListNode* back_dummy = new ListNode(0);
        ListNode* front_ptr = front_dummy;
        ListNode* back_ptr = back_dummy;
        ListNode* traversal_ptr = head;
        
        while (traversal_ptr != NULL) {
            if (traversal_ptr->val < x) {
                front_ptr->next = traversal_ptr;
                front_ptr = front_ptr->next;
            } else {
                back_ptr->next = traversal_ptr;
                back_ptr = back_ptr->next;
            }
            traversal_ptr = traversal_ptr->next;
        }
        
        front_ptr->next = back_dummy->next;
        back_ptr->next = NULL;
        head = front_dummy->next;
        delete front_dummy;
        delete back_dummy;
        
        return head;
    }
};