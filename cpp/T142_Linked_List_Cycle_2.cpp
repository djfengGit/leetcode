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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;      // 必须采用此种初始化方式，详见T141
        
        // 快指针绕circle追slow指针，一定能追上
        while (fast_ptr != NULL && fast_ptr->next != NULL)  // 没有环
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr) {
                break;
            }
        }
        
        if (slow_ptr != fast_ptr) {
            return NULL;
        }
        
        fast_ptr = head;
        while (slow_ptr != fast_ptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        
        return fast_ptr;
    }
};