/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Helper function */
void inorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorder(root->right, arr, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // enough space
    *returnSize = 0;

    inorder(root, result, returnSize);
    return result;
}
