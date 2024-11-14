/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void  MiddleorderT(struct TreeNode* cur, int* num, int* index)
{
    if(cur == NULL)
        return;
    MiddleorderT(cur->left, num, index);
    num[(*index)++ ] = cur->val;
    MiddleorderT(cur->right, num, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* num = (int* )malloc(sizeof(int) * 100);
    * returnSize = 0;
    MiddleorderT(root, num, returnSize);
    return num;
}
// @lc code=end

