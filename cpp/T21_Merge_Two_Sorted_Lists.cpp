/*- 两种方法：1、模拟老师帮小学生排队，以l1为已排好的队列，将l2元素插进去；较麻烦，需要单独考虑是否已到链表尾的情况；
            2、合并排序思路，引入头结点便于操作；
            本题采用方法2
  -*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* ptr = dummy_head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        // 其中一个链表已经遍历到尾部，直接添加另一个链表剩余节点
        if (l1 == NULL) {
            ptr->next = l2;
        } else {
            ptr->next = l1;
        }
        
        return dummy_head->next;
    }
};