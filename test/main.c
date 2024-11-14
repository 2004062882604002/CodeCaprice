#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int index; // 存储元素的索引
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int index) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->index = index;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1; // 队列为空
    }
    QueueNode* temp = q->front;
    int dequeuedIndex = temp->index;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeuedIndex;
}

int peek(Queue* q, int* nums) {
    if (q->front == NULL) {
        return -1; // 队列为空
    }
    return nums[q->front->index]; // 返回队列头部的最大值
}

void q_push(Queue* q, int* nums, int index, int k) {
    // 移除队列中所有小于当前元素的索引，并且确保队列中存储的索引是有效的
    while (q->rear != NULL && nums[q->rear->index] < nums[index]) {
        dequeue(q);
    }
    enqueue(q, index);
}

void q_pop(Queue* q, int index) {
    // 仅当队列头部的元素索引等于当前元素索引时，才出队
    if (q->front != NULL && q->front->index == index) {
        dequeue(q);
    }
}

void clearQueue(Queue* q) {
    while (q->front != NULL) {
        dequeue(q);
    }
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL || numsSize == 0 || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    Queue* queue = createQueue();
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    // 初始化队列，存储前k个元素的索引
    for (int i = 0; i < k; i++) {
        q_push(queue, nums, i, k);
    }
    result[0] = peek(queue, nums);

    for (int i = k; i < numsSize; i++) {
        q_pop(queue, i - k); // 移除窗口外的元素
        q_push(queue, nums, i, k); // 加入当前元素
        result[i - k + 1] = peek(queue, nums); // 获取当前窗口的最大值
    }

    clearQueue(queue); // 清除队列中的所有节点
    free(queue); // 释放队列结构体
    return result;
}

int main() {
    int nums[] = {1, 3, 1, 2, 0, 5};
    int numsSize = 6;
    int k = 3;
    int returnSize;
    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    // 输出结果
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
