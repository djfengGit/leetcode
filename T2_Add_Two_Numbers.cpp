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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0 && l1->next == NULL) {
            return l2;            
        } else if (l2->val == 0 && l2->next == NULL) {
            return l1;
        } else {
            int tmp = 0;
            int carry = 0;  // 进位标志
            
       //     ListNode* result = (ListNode *)malloc(sizeof(ListNode));  //使用此句，执行时间为4ms
            ListNode* result = new ListNode(0); //使用此句，执行时间为8ms；因为new云算法调用了构函
            ListNode* p_result = result;
            
            while (l1 != NULL || l2 != NULL) {
                tmp = (l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry;
                carry = tmp / 10;
                tmp %= 10;
                p_result->next = new ListNode(tmp);
                p_result = p_result->next;
                
                if (l1 != NULL) {
                    l1 = l1->next;  //当链表节点遍历完成，  
                }
                if (l2 != NULL) {
                    l2 = l2->next;  
                }
            }
            
            if (carry == 1) {
                p_result->next = new ListNode(1);
            }
            return result->next;    // 空间牺牲了头结点
        }   
    }
};

/**
 * 考察点：链表的遍历，新节点的生成
 * 难点：进位的处理
 */
