/* --------------------------------------------------------
 * @note: 考察单链表的指针操作（很容易出错，要一步步画图，不要图快）
 * @solution: 加头结点、快慢指针
 * --------------------------------------------------------
 */


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* slow_ptr = dummy_head;
        ListNode* fast_ptr = head;
        
        // 注意判断条件的次序，代表两种情况，不可颠倒
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            slow_ptr->next = fast_ptr->next;
            fast_ptr->next = slow_ptr->next->next;
            slow_ptr->next->next = fast_ptr;
            
            slow_ptr = fast_ptr;
            fast_ptr = fast_ptr->next;
        }
        
        return dummy_head->next;
    }
};