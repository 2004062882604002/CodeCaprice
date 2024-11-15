/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // 结果数组
    int* result = (int* )malloc(sizeof(int) *2000);
    *returnSize = 0;
    // 创建模拟栈
    struct TreeNode* stk[200];
    int stp_top = 0;   // 栈顶
    // 基础判断
    if(root == NULL)
        return result;
    struct TreeNode* node = root;
    stk[stp_top++] = root; // 进栈push
    while(stp_top > 0)
    {
        // 中节点
        node = stk[stp_top - 1];
        stp_top--;  
        result[(*returnSize)++] = node->val;
        if(node->right) stk[stp_top++] = node->right;
        if(node->left) stk[stp_top++] = node->left;
    }
    return result;
}
// @lc code=end

