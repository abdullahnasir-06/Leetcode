bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both are NULL → same
    if (p == NULL && q == NULL)
        return true;

    // If one is NULL but the other isn't → not same
    if (p == NULL || q == NULL)
        return false;

    // If values differ → not same
    if (p->val != q->val)
        return false;

    // Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
