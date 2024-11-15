/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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
int getshot(struct TreeNode* root)
{
    if(root == NULL) return 0;
    if(root->right == NULL && root->left != NULL)
        return 1 + getshot(root->left);
    else if(root->right != NULL && root->left == NULL)
        return 1 + getshot(root->right);
    else 
        return 1 + fmin(getshot(root->left), getshot(root->right));
}
int minDepth(struct TreeNode* root) {
    return getshot(root);
}
// @lc code=end

