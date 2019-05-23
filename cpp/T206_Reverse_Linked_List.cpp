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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* slow_ptr = dummy_head;
        ListNode* fast_ptr = slow_ptr->next;
        ListNode* tmp_ptr = NULL;
        //ListNode* tail_ptr = head;
        while (fast_ptr != NULL) {
            tmp_ptr = fast_ptr->next;
            fast_ptr->next = slow_ptr;
            slow_ptr = fast_ptr;
            fast_ptr = tmp_ptr;
        }
        
        dummy_head->next = slow_ptr;
        head->next = NULL;
        head = dummy_head->next;
        delete dummy_head;
        
        return head;
    }
};