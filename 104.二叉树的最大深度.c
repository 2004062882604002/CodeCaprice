/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
int gethigh(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1 + fmax(gethigh(root->left),gethigh(root->right));
}
int maxDepth(struct TreeNode* root) {
    return gethigh(root);
}
// @lc code=end

