/*
 * @lc app=leetcode.cn id=226 lang=c
 *
 * [226] 翻转二叉树
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
struct TreeNode* swap(struct TreeNode* root)
{
    struct TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    return root;
}

struct TreeNode* fun(struct TreeNode* root)
{
    if(root == NULL)
        return root;
    swap(root);
    fun(root->left);
    fun(root->right);
    return root;
}
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* res = fun(root);
    return res;
}
// @lc code=end

