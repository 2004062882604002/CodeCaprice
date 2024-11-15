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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int* )malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* skt[2000];
    int skt_top = 0;
    struct TreeNode* node = root;
    while(node != 0 || skt_top > 0)  // 判断栈是否为空
    {
        if(node != NULL)
        {
            skt[skt_top++] = node;
            node = node->left;
        }
        else
        {
            node = skt[--skt_top];
            res[(*returnSize)++] = node->val;
            node = skt[skt_top];
            node = node->right;
        }
    }
    return res;
}
// @lc code=end

