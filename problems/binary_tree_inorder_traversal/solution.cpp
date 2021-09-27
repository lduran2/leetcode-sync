/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; /* the resulting vector */

        stack<TreeNode*> tree_stack;        /* holds tree nodes to traverse again */
        TreeNode** top;                     /* top of tree stack for convenience */

        /* which field of the node to process */
        enum { LEFT,    /* step left */
            VALUE,      /* read value */
            RIGHT       /* step right */
        } node_state = LEFT; /* start facing left */

        /* start with the root */
        tree_stack.push(root);

        /* loop until enter tree is consumed through the stack */
        while (!tree_stack.empty()) {
            /* update top */
            top = &tree_stack.top();
            switch (node_state) {
                case LEFT:
                    /* if the current node is null */
                    if (*top == nullptr) {
                        /* step back to the parent node */
                        tree_stack.pop();
                        /* signal to read its value */
                        node_state = VALUE;
                    } /* if (*top == nullptr) */
                    else {
                        /* otherwise, add the next left node to the stack */
                        tree_stack.push((*top)->left);
                        /* hold node_state */
                    } /* if (*top == nullptr) else */
                break; /* case LEFT */
                case VALUE:
                    /* read the value of this node */
                    result.push_back((*top)->val);
                    /* step right */
                    node_state = RIGHT;
                break; /* case VALUE */
                case RIGHT:
                    /* replace the parent node (which we just came from) with this node */
                    *top = (*top)->right;
                    /* step left */
                    node_state = LEFT;
                break; /* case RIGHT */
            } /* switch (node_state) */
        } /* while (!tree_stack.empty()) */

        return result;
    }
};