/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/** the maximum possible index */
const int unsigned MAX_INT = ((int signed)((~0u) >> 1));

int sizeOf(struct ListNode* head);
int seek(struct ListNode** list, int index);
struct ListNode* removeTail(struct ListNode* head, int index);
void insertNodeAfter(struct ListNode* new_node, struct ListNode* reference_node);
void reverseList(struct ListNode** list);

void reorderList(struct ListNode* head){
    struct ListNode* phead[2] = { head, NULL }; /* iterators on head end half */

    struct ListNode* ptail[2];  /* iterators on the tail end */
    int idiv;                   /* index to divide the list */
    /* 0 <= #(el in head) - #(el in tail) <= 1 */

    int size = sizeOf(head);
    idiv = ((sizeOf(head) + 1) >> 1);   /* find the point of division */
    *ptail = removeTail(head, idiv);    /* remove the tail end */
    reverseList(ptail);

    /* loop through the tail end */
    while (*ptail){
        /* backup next in the iterators */
        phead[1] = phead[0]->next;
        ptail[1] = ptail[0]->next;
        /* insert tail after head */
        insertNodeAfter(*ptail, *phead);
        /* update the iterators */
        phead[0] = phead[1];
        ptail[0] = ptail[1];
    } /* while (*ptail) */
}

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
 * Seek in the given list, up until index or the end of the list.
 * @param list : ListNode** = pointer to the head of the list
 * @param index : int = to which to seek
 * @return # elements actually sought
 */
int seek(struct ListNode** list, int index){
    int i_seeked = 0;   /* size of the linked list so far */
    /* loop through the linked list or until seeked to index */
    for (; (*list && (i_seeked < index)); *list = (*list)->next)
    {
        ++i_seeked;
    } /* for (; (*list && (i_seeked < index)); ) */
    return i_seeked;
} /* int sizeOf(struct ListNode* head) */

/**
 * Removes every element in a tail starting at the given index.
 * @param head : struct ListNode* = from which to remove
 * @param index : int = at which to make the tail
 * @return the tail removed
 */
struct ListNode* removeTail(struct ListNode* head, int index){
    struct ListNode* tail;      /* the node starting the tail */
    struct ListNode* pre_tail;  /* node before the tail */
    pre_tail = head;            /* initialize to the head */
    seek(&pre_tail, (index - 1));   /* seek to node before given index */
    tail = pre_tail->next;      /* store the tail */
    pre_tail->next = NULL;      /* null out the next element in the head end */
    return tail;                /* return the tail end */
} /* struct ListNode* removeTail(struct ListNode* head, int index) */

/**
 * Inserts the new node after the reference node.
 * @param new_node : struct ListNode* = to insert
 * @param reference_node : struct ListNode* = after which to insert
 */
void insertNodeAfter(struct ListNode* new_node, struct ListNode* reference_node){
    new_node->next = reference_node->next;
    reference_node->next = new_node;
} /* void insertNodeAfter(struct ListNode* new_node, struct ListNode* reference_node) */

/**
 * Reverses the given list.
 * @param list : struct ListNode** = to reverse
 */
void reverseList(struct ListNode** list){
    struct ListNode* curr[2] = { *list, NULL };  /* the current and next node */
    /* before the head of the new list */
    struct ListNode new_phead = {
        .val = 0,
        .next = NULL
    };
    struct ListNode* new_list = &new_phead; /* the reversed list */

    /* loop through the nodes, inserting each one as the head */
    for (; curr[0]; curr[0] = curr[1]) {
        curr[1] = curr[0]->next;
        insertNodeAfter(curr[0], new_list);
    } /* for (; curr[0]; ) */

    /* return with the first element (after pre_head) */
    *list = new_list->next;
} /* void reverseList(struct ListNode** list) */
