/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;  /* the carry */
        ListNode* curr = new ListNode;  /* node currently added */
        ListNode* result = curr; /* the resulting list */

        /* if neither list or the carry is exhausted */
        while (l1 || l2 || carry) {
            /* create and advance to next node */
            curr = curr->next = new ListNode;
            /* add values, but guard against null */
            curr->val = (l1 ? l1->val : 0)
                + (l2 ? l2->val : 0)
                + carry;

            /* check for carry */
            if (curr->val >= 10) {
                /* borrow from curr->val if needed */
                carry = 1;
                curr->val -= 10;
            }
            else {
                /* otherwise, reset carry */
                carry = 0;
            }

            /* advance the lists */
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        /* the first node is empty, so skip it */
        return result->next;
    }
};