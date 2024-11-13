/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start



typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
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
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q = createQueue();
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    // 将新元素入队
    enqueue(obj->q, x);
    
    // 将队列中的所有元素（除了刚入队的元素）出队并重新入队，使新元素位于队列的前面
    int size = 0;
    QueueNode* current = obj->q->front;
    while (current) {
        size++;
        current = current->next;
    }
    for (int i = 0; i < size - 1; ++i) {
        int frontValue = dequeue(obj->q);
        enqueue(obj->q, frontValue);
    }
}

int myStackPop(MyStack* obj) {
    // 直接出队，因为队列的第一个元素就是栈的栈顶元素
    return dequeue(obj->q);
}

int myStackTop(MyStack* obj) {
    // 队列的第一个元素就是栈的栈顶元素
    if (isQueueEmpty(obj->q)) {
        return -1; // 栈为空
    }
    return obj->q->front->data;
}


bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    while (!isQueueEmpty(obj->q)) {
        dequeue(obj->q);
    }
    free(obj->q);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
// @lc code=end

