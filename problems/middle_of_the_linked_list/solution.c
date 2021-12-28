/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* the maximum possible index */
const int unsigned MAX_INT = ((int signed)(((int unsigned)(-1)) >> 1));

/* size function */
int sizeOf(struct ListNode* head);
/* seek function */
int seek(struct ListNode** phead, int index);

struct ListNode* middleNode(struct ListNode* head){

    struct ListNode* mid;   /* middle node */
    int imid;               /* index of middle node */

    mid = head; /* initialize to the head */
    imid = (sizeOf(mid) >> 1);  /* calculate the midpoint */
    seek(&mid, imid);   /* seek to it */

    return mid;
} /* struct ListNode* middleNode(struct ListNode* head) */

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
