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
void PreorderT(struct TreeNode* root, int* num, int* index) {
    if (root == NULL) {
        return;
    }
    num[(*index)++] = root->val; 
    PreorderT(root->left, num, index);
    PreorderT(root->right, num, index);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0; 
    int* num = (int*)malloc(sizeof(int) * 100); 
    if (num == NULL) {
        return NULL; 
    }
    PreorderT(root, num, returnSize); 
    return num;
}
// @lc code=end

