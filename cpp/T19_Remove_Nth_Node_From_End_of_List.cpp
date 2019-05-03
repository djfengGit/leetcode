/* -----------------------------------------------------
 * @brief:
 * @note:链表有头结点大大方便操作；单链表遍历的技巧：快慢指针
 *
 *
 ------------------------------------------------------*/

/*- 1、无头节点，两次遍历 需要单独考虑删除的节点恰好是头结点的情况-*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) {
            return head;
        }
        
        int nodeNum = 0;
        ListNode* ptr = head;
    
        while (ptr != NULL) {
            nodeNum++;
            ptr = ptr->next;            
        }
        
        if (nodeNum <= 1) {
            delete ptr;
            ptr = NULL;
            head = NULL;
            return head;
        }
        
        ptr = head;
        if (nodeNum == n) {
            head = head->next;
            delete ptr;
            return head;
        }
        
        for (int i = 1; i < nodeNum - n; i++) {
            ptr = ptr->next;
        }
        
        ListNode* removeNth = ptr->next;
        ptr->next = removeNth->next;
        delete removeNth;
          
        return head;
    }
};

/*- 2、有头节点，两次遍历 -*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        int nodeNum = 0;
        ListNode* ptr = dummy_head;
        
        while (ptr != NULL) {
            nodeNum++;
            ptr = ptr->next;
        }
        
        nodeNum -= n;
        ptr = dummy_head;
        while (nodeNum > 1) {   // 注意此处的 nodeNum > 1
            nodeNum--;
            ptr = ptr->next;
        }
        ListNode* ptr_tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete ptr_tmp;
        return dummy_head->next;        
    }
};


/*- 3、有头节点，采用快慢指针，只需要一次遍历 -*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode* fast_ptr = dummy_head;
        ListNode* slow_ptr = dummy_head;
        while (n > 0) {     // 快指针先走n个节点，快慢指针之间始终差n个节点
            n--;
            fast_ptr = fast_ptr->next;
        }
        while (fast_ptr->next != NULL) { // 快指针走到尾节点，慢指针恰好走到待删除节点的上一个节点
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        ListNode* ptr_tmp = slow_ptr->next;
        slow_ptr->next = slow_ptr->next->next;
        delete ptr_tmp;
        return dummy_head->next;
    }
};