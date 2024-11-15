/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool equ(struct TreeNode* Lnode, struct TreeNode* Rnode)
{
    if(Lnode == NULL && Rnode == NULL) return true;
    else if(Lnode == NULL && Rnode != NULL) return false;
    else if(Lnode != NULL && Rnode == NULL) return false;
    else if(Lnode->val != Rnode->val ) return false;
    bool outside = equ(Lnode->left, Rnode->right);
    bool inside = equ(Lnode->right, Rnode->left);
    bool res = outside && inside;
    return res;
}
bool isSymmetric(struct TreeNode* root) {
    return equ(root->left, root->right);
}
// @lc code=end

