/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层序遍历
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // 结果数组存储数据
    int** res = (int** )malloc(sizeof(int*) * 2000);
    *returnSize = 0;  // 结果数组的下标
    // 每行节点数要存储返回retureColumSizes
    int columnSizes[2000];
    // 模拟队列
    struct TreeNode* queue[2000];
    int rear = 0;   // 队列尾
    int head = 0;   // 队列头
    queue[rear++] = root; // 录入根节点

    if(!root) return NULL;

    while(head != rear)
    {
        res[(*returnSize)] = (int* )malloc(sizeof(int) * (rear - head));
        columnSizes[(*returnSize)] = rear - head;
        int start = head;
        head = rear;

        for(int i = start; i < head; i++)
        {
            res[(*returnSize)][i - start] = queue[i]->val;
            if(queue[i]->left) queue[rear++] = queue[i]->left;
            if(queue[i]->right) queue[rear++] = queue[i]->right;
        }
        (*returnSize)++;
    }
    *returnColumnSizes = (int* )malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++)
        (*returnColumnSizes)[i] = columnSizes[i];
    return res;
}
// @lc code=end

