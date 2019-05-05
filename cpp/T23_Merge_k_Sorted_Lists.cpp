/* --------------------------------------------
 * @note: 1、priority_queue 的使用及内部实现
 *        2、list的正确理解
 *        3、Divide and Conquer (分治策略)
 * --------------------------------------------
 */

/*- 1、priority_queue  空间只额外增加了头结点 
    使用pair< >，是为了在使用priority_queue时不重载operator < 
    priority_queue默认使用 < 来排序，对结构体入队时，需要重载 < 
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* ptr_node = dummy_head, *node_tmp_ptr = NULL;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*> >, greater<pair<int, ListNode*> > > pq;
        
        for (auto list: lists) {
            if (list) {
                pq.push(make_pair(list->val, list));
            }
        }       // 正确理解lists，此次循环只有每个链表的第一个节点被入队
        
 
/*       while (!pq.empty()) {  // debug
            cout << pq.top().first << endl;
            pq.pop();
        }
   */       
        
        while (!pq.empty()) {
            pair<int, ListNode*> top = pq.top();
            pq.pop();   // 一次出队完成，
            node_tmp_ptr = top.second;
            ptr_node->next = node_tmp_ptr;

            ptr_node = node_tmp_ptr;
            node_tmp_ptr = node_tmp_ptr->next;

            // 将当前出队节点的下一个节点入队（因为是有序链表）；
            if (node_tmp_ptr != NULL) {
                pq.push(make_pair(node_tmp_ptr->val, node_tmp_ptr));
            }
        }
        return dummy_head->next;
    }
};

/*- 1、priority_queue  空间只额外增加了头结点 
    another method: 重载 < 
  -*/



/*- 2、分治策略 -*/