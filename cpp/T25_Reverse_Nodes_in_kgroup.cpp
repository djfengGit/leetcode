/* 采用了T92的链表翻转方法，递归实现，不用递归反而比较麻烦 */

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) {
            return head;
        }
        
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* fast_ptr = dummy_head;
        
        int i = 0;
        while (i < k && fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
            i++;
        }
        
        if (fast_ptr == NULL) {
            return head;
        }

        ListNode* slow_ptr = dummy_head;
        ListNode* connect_ptr = slow_ptr;
        ListNode* tail_ptr = slow_ptr->next;
        ListNode* tmp_ptr = NULL;
        fast_ptr = slow_ptr->next;
        int t = 0;
        while (t < k && fast_ptr != NULL) {
            tmp_ptr = fast_ptr->next;
            fast_ptr->next = slow_ptr;
            slow_ptr = fast_ptr;
            fast_ptr = tmp_ptr;
            t++;
        }
        
        connect_ptr->next = slow_ptr;
        tail_ptr->next = fast_ptr;
        
        head = dummy_head->next;
        delete dummy_head;
        
        if (fast_ptr != NULL) {
            int t = k;
            tail_ptr->next = reverseKGroup(fast_ptr, t);
        }
        
        return head;
    }
};