/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode preMergedList = new ListNode();   /* full list */
        ListNode newNode = preMergedList;  /* current node */
        ListNode temp; /* for swapping the lists */

        /* if list 1 is exhausted, move list 2 in */
        if (l1 == null) {
            l1 = l2;
            l2 = null;
        }

        /* loop until the shorter list is exhausted */
        while (l2 != null) {
            /* choose the lower next value of the two lists */
            if (l2.val < l1.val) {
                /* swap if l2 is lower */
                temp = l1;
                l1 = l2;
                l2 = temp;
            }

            /* merge the lower value in and procedue */
            newNode.next = new ListNode(l1.val);
            newNode = newNode.next;
            /* move to next in longer list */
            l1 = l1.next;

            /* if list 1 is exhausted, move list 2 in */
            if (l1 == null) {
                l1 = l2;
                l2 = null;
            } /* if (l1 == null) */
        } /* while (l2 != null) */
    
        /* add the tail of the leftover list (l1) to the merged list */
        newNode.next = l1;

        return preMergedList.next;
    }
}