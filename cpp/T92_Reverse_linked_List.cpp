/**
* @note: important: 链表翻转算法，逐节点推进
 */

/**
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return head;
        }

        ListNode* slow_ptr = NULL;
        ListNode* fast_ptr = head;
        while (m > 1) {
            slow_ptr = fast_ptr;
            fast_ptr = fast_ptr->next;
            m--;
            n--;
        }
        
        ListNode* connect_ptr = slow_ptr;
        ListNode* tail_ptr = fast_ptr;
        ListNode* tmp_ptr = NULL;        
        
        while (n > 0) {
            tmp_ptr = fast_ptr->next;
            fast_ptr->next = slow_ptr;
            slow_ptr = fast_ptr;
            fast_ptr = tmp_ptr;
            n--;
        }
        
        if (connect_ptr != NULL) {
            connect_ptr->next = slow_ptr;
        } else {    // 当整个链表全反转时，connect_ptr = slow_ptr执行时 connect_ptr == NULL
            head = slow_ptr;
        }
        
        tail_ptr->next = fast_ptr;        
        return head;
    }
};

/* 加入头结点，操作较方便 */

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* slow_ptr = dummy_head;
        ListNode* fast_ptr = dummy_head;
        while (m > 0) {
            slow_ptr = fast_ptr;
            fast_ptr = fast_ptr->next;
            m--;
            n--;
        }
        
        ListNode* connect_ptr = slow_ptr;
        ListNode* tail_ptr = fast_ptr;
        ListNode* tmp_ptr = NULL;        
        
        while (n >= 0) {
            tmp_ptr = fast_ptr->next;
            fast_ptr->next = slow_ptr;
            slow_ptr = fast_ptr;
            fast_ptr = tmp_ptr;
            n--;
        }
        
/*      if (connect_ptr != NULL) {
            connect_ptr->next = slow_ptr;
        } else {
            head = slow_ptr;
        }
  */    
        // 当整个链表全反转时，connect_ptr = slow_ptr执行时 connect_ptr == NULL
        if (connect_ptr == dummy_head) {
            dummy_head->next = slow_ptr;
        } else {
            connect_ptr->next = slow_ptr;
        }
        
        tail_ptr->next = fast_ptr;
        head = dummy_head->next;
        delete dummy_head;
        return head;
    }
};