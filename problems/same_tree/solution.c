/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    /* base cases: at least one branch is NULL */
    /* if the first branch is NULL */
    if (p == NULL) {
        /* return whether the second branch is NULL */
        return (q == NULL);
    } /* if (p == NULL) */
    /* otherwise and if q is NULL, */
    else if (q == NULL) {
        /* then the branches are unequal */
        return false;
    } /* else if (q == NULL) */
    
    /* inductive step: */
    return (p->val == q->val)               /* compare values */
        && isSameTree(p->left, q->left)     /* and left branches */
        && isSameTree(p->right, q->right);  /* and right branches */
}