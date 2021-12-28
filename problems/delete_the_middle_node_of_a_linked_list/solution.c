/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* the maximum possible index */
const int unsigned MAX_INT = ((int signed)(((int unsigned)(-1)) >> 1));

/* node remove function */
void removeNextNode(struct ListNode* node);
/* size function */
int sizeOf(struct ListNode* head);
/* seek function */
int seek(struct ListNode** phead, int index);

struct ListNode* deleteMiddle(struct ListNode* head){
    /* value of the node before the head */
    struct ListNode deref_pre_head = {
        .val = 0,
        .next = head
    };

    struct ListNode* pre_mid;   /* node before middle */
    int imid;                   /* index of middle node */

    imid = (sizeOf(head) >> 1); /* calculate the midpoint */

    pre_mid = &deref_pre_head;  /* initialize to the pre-head */
    seek(&pre_mid, imid);       /* seek to node before midpoint */
    removeNextNode(pre_mid);    /* remove the next node */

    /* return the list */
    return deref_pre_head.next;
} /* struct ListNode* middleNode(struct ListNode* head) */

/**
 * Removes the node after the given node.
 * @param node : struct ListNode* = whose next node to remove
 */
void removeNextNode(struct ListNode* node) {
    /* defend against no node or next node */
    if ((!node) || (!(node->next))) return;
    node->next = node->next->next;  /* skip the next element */
} /* void removeNextNode(struct ListNode* node)*/

/**
 * Finds the size of a list.
 * @param head : struct ListNode* = to size
 * @return the size of the linked list at `head`.
 */
int sizeOf(struct ListNode* head) {
    int size;   /* size of the list */
    size = seek(&head, MAX_INT);    /* seek until end, saving # sought */
    return size;
} /* int sizeOf(struct ListNode* head) */

/**
 * Seek in the list to which is pointed, up until index or the end of
 * the list.
 * @param phead : ListNode** = pointer to the head of the list
 * @param index : int = to which to seek
 * @return # elements actually sought
 */
int seek(struct ListNode** phead, int index){
    int i_seeked = 0;   /* size of the linked list so far */
    /* loop through the linked list or until seeked to index */
    for (; (*phead && (i_seeked < index)); *phead = (*phead)->next)
    {
        ++i_seeked;
    } /* for (; (*phead && (i_seeked < index)); ) */
    return i_seeked;
} /* int sizeOf(struct ListNode* head) */

