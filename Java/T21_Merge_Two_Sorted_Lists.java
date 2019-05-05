/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode node_ref = dummyHead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                node_ref.next = l1;
                l1 = l1.next;
            } else {
                node_ref.next = l2;
                l2 = l2.next;
            }
            node_ref = node_ref.next;
        }
        
        if (l1 == null) {
            node_ref.next = l2;
        } else {
            node_ref.next = l1;
        }
        return dummyHead.next;
    }
}