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
    bool hasCycle(ListNode *head) {
        if (head == NULL ||head->next == NULL) {
            return false;
        }
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head->next;    // 采用此种初始化方式，快指针追上慢指针需要的迭代次数多
        // 快指针绕circle追slow指针，一定能追上
        while (slow_ptr != fast_ptr)
        {// 没有环
            if (fast_ptr == NULL || fast_ptr->next == NULL) {
                return false;
            }
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return true;
    }
};

// 采用第二种初始化方式

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL ||head->next == NULL) {
            return false;
        }
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        // 快指针绕circle追slow指针，一定能追上
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {// 没有环
            // 应该先迭代一次，因为初始化时 slow_ptr == fast_ptr
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr) {
                break;
            }
        }
        if (slow_ptr != fast_ptr) {
            return false; // 无环
        } else {
            return true;
        }
    }
};