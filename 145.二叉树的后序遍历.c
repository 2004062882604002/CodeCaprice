/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
void PostorderT(struct TreeNode* cur, int* num, int* index){
    if(cur == NULL)
        return;
    PostorderT(cur->left, num, index);
    PostorderT(cur->right, num, index);
    num[(*index )++] = cur->val;
} 

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* num = (int* )malloc(sizeof(int) * 100);
    *returnSize = 0;
    PostorderT(root, num, returnSize);
    return num;
}
// @lc code=end

