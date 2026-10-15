/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static void inorder(struct TreeNode* node, int* res, int* size) {
    if (node == NULL) return;
    inorder(node->left, res, size);
    res[(*size)++] = node->val;
    inorder(node->right, res, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}