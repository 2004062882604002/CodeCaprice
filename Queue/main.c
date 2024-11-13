// 队列 —— 先进先出
// enqueue dequeue peek
#include <stdio.h>

typedef struct QueueNode{
    int data;
    struct QueueNode* next;

}QueueNode;

typedef struct  Queue{
    struct QueueNode* front;
    struct QueueNode* rear;
}Queue;

QueueNode* creatQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);

int main(void)
{
    Queue* q = creatQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("出队元素: %d\n", dequeue(q));
    printf("出队元素: %d\n", dequeue(q));

    return 0;
}

QueueNode* creatQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value)
{
    QueueNode* NewQueue = (QueueNode* )malloc(sizeof(QueueNode));
    NewQueue->next = NULL;
    NewQueue->data = value;
    if (q->rear == NULL) {  // 如果队列为空
        q->front = q->rear = NewQueue;
        return;
    }
    q->rear->next = NewQueue;
    q->rear = NewQueue;
}

int dequeue(Queue* q)
{
    QueueNode* temp = q->front;
    int dequeuedValue = temp->next->data;
    q->front = q->front->next;
    free(temp);
    return dequeuedValue;
}

int peek(Queue* q)
{
    int front_value = q->front->data;
    return front_value;
}
