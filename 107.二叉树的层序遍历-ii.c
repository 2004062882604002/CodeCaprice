/*
 * @lc app=leetcode.cn id=107 lang=c
 *
 * [107] 二叉树的层序遍历 II
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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** res = (int** )malloc(sizeof(int*) * 2000);
    *returnSize = 0;
    int columnSizes[2000];

    if(!root) return NULL;

    struct TreeNode* queue[2000];
    int head = 0;
    int rear = 0;
    queue[rear++] = root;

    while(head != rear)
    {
        columnSizes[(*returnSize)] = rear - head;
        res[(*returnSize)] = (int*)malloc(sizeof(int) * (rear - head));
        int start = head;
        head = rear;
        
        for(int i = start; i < head; i++)
        {
            res[(*returnSize)][i - start] = queue[i]->val;
            if(queue[i]->left)  queue[rear++] = queue[i]->left;
            if(queue[i]->right)  queue[rear++] = queue[i]->right;
        }
        (*returnSize)++;
    }
    *returnColumnSizes = (int* )malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = columnSizes[i];
    }

    int left = 0;
    int right = *returnSize;
    while(left < right)
    {
        int* tmp = res[left];
        res[left] = res[right - 1];
        res[right - 1] = tmp;

        int mid = (*returnColumnSizes)[left];
        (*returnColumnSizes)[left] = (*returnColumnSizes)[right - 1];
        (*returnColumnSizes)[right - 1] = mid;

        left++;
        right--;
    }
    return res;
}
// @lc code=end

