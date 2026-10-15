/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    int sum = 0;
    struct TreeNode* l = root->left;
    if (l != NULL && l->left == NULL && l->right == NULL) {
        sum += l->val;
    } else {
        sum += sumOfLeftLeaves(l);
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}