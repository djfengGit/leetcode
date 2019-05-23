/**
 * solution 1: Brute Force
 *      time complexity: O(mn)
 *      space complexity: O(1)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        for (ListNode* ptrA = headA; ptrA != NULL; ptrA = ptrA->next) {
            for (ListNode* ptrB = headB; ptrB != NULL; ptrB = ptrB->next) {
                if (ptrA == ptrB) {
                   return ptrA;
                }
            }
        }
        return NULL;
    }
};


/* 一种简便方法，先找到A、B的总节点数目，若 A > B，则A先走到与B同长度的节点，然后A、B再一同向前走；反之亦然 
    O(m+n) 、 O(1) */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* ptrA = headA, *ptrB = headB;
        int nodeNumA = 0, nodeNumB = 0;
        while (ptrA != NULL) {
            nodeNumA++;
            ptrA = ptrA->next;
        }
        while (ptrB != NULL) {
            nodeNumB++;
            ptrB = ptrB->next;
        }

        ptrA = headA;
        ptrB = headB;

        if (nodeNumA >= nodeNumB) {
            for (int i = 0; i < nodeNumA - nodeNumB; i++) {
                ptrA = ptrA->next;
            }
        } else {
            for (int i = 0; i < nodeNumB - nodeNumA; i++) {
                ptrB = ptrB->next;
            }
        }

        while (ptrA != ptrB && ptrA != NULL && ptrB != NULL) {
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};

/* solution 3: two pointers */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)  {
            return NULL;
        }
        ListNode* ptrA = headA, *ptrB = headB;
        int flag_i = 0;
        while (ptrA != ptrB) {
            ptrB = (ptrB != NULL) ? ptrB->next : headA; // 若两链表无交点，有陷入死循环的风险，在下面进行处理
            if (ptrA != NULL) {
                ptrA = ptrA->next;
            } else {
                ptrA = headB;
                flag_i++;
                if (flag_i >= 2) {
                    ptrA = NULL;
                    break;
                }
            }
        }
        return ptrA;
    }
};

