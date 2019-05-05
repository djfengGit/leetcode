
/* 三指针法，注意逻辑 */

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
        
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* slower_ptr = dummy_head;
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;

        while (fast_ptr != NULL) {
            if (slow_ptr->val == fast_ptr->val) {   // 遇到相通的节点，fast_ptr向前走，slow_ptr不动
                fast_ptr = fast_ptr->next;
            } else if (slow_ptr->next == fast_ptr) { // 不满足第一条件时，有两种情况，此处处理第二种情况：连续多个节点不相同
                slower_ptr = slow_ptr;
                slow_ptr = fast_ptr;
                fast_ptr = fast_ptr->next;
            } else { // 处理第一种情况，连续多个节点相同后，遇到一个不相同节点，删除之前的相同节点
                slower_ptr->next = fast_ptr;
                slow_ptr = fast_ptr;
                fast_ptr = fast_ptr->next;
            }
        }
        if (slow_ptr->next != fast_ptr) {   // fast_ptr == NULL; slow_ptr与fast_ptr之间可能还有连续相同节点存在
            slower_ptr->next = NULL;
        }
        
        return dummy_head->next;
    }
};