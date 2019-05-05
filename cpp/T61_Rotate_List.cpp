/* ----------------------------------------
 * @note: 加入头结点、快慢指针，操作更方便
 * ----------------------------------------
 */


/* 1、循环移动节点；注意出现循环的情况 k %= node_num; */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* dummy_head = new ListNode(0);
        ListNode* traversal_ptr = dummy_head;
        dummy_head->next = head;
        
        int node_num = 0;
        
        while (traversal_ptr->next != NULL) {
            traversal_ptr = traversal_ptr->next;
            node_num++;    // 遍历链表，找出总节点数
        }
        
        k %= node_num;    // 注意k很大，n很小时，出现循环的情况；k == n时，相当于不用进行循环
        traversal_ptr = dummy_head;
        
        for (; k > 0; k--) {
            while (traversal_ptr->next->next != NULL) {
                traversal_ptr = traversal_ptr->next;
            }
            traversal_ptr->next->next =  dummy_head->next;
            dummy_head->next = traversal_ptr->next;
            traversal_ptr->next = NULL;
            traversal_ptr = dummy_head;
        }
    
        return dummy_head->next;
    }
};

/* 2、
 * 将尾部的k个节点直接移动到头部；头结点加快慢指针，快指针比慢指针先走k步
 * 由于少了很多指针重定向，速度更快，同时内存消耗更少
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy_head = new ListNode(0);
        ListNode* slow_ptr = dummy_head, *fast_ptr = dummy_head;
        dummy_head->next = head;

        int node_num = 0;
        while (fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next;
            node_num++;    // 遍历链表，找出总节点数
        }

        k %= node_num;    // 注意k很大，n很小时，出现循环的情况；k == n时，相当于不用进行循环
        fast_ptr = dummy_head;

        for (; k > 0; k--) {
            fast_ptr = fast_ptr->next;
        }
        while (fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        fast_ptr->next = dummy_head->next;
        dummy_head->next = slow_ptr->next;
        slow_ptr->next = NULL;
        
        return dummy_head->next;
    }
};