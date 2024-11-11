#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int stackInTop, stackOutTop;
    int stackIn[100], stackOut[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue* )malloc(sizeof(MyQueue));
    queue->stackInTop = 0;
    queue->stackOutTop = 0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackInTop)++] = x;
}

int myQueuePop(MyQueue* obj) {
    int stackInTop = obj->stackInTop;
    int stackOutTop = obj->stackOutTop;
    if(stackOutTop == 0) {
        while(stackInTop > 0) {
            obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];
        }
    }
    //将第二个栈中栈顶元素（队列的第一个元素）出栈，并保存
    int top = obj->stackOut[--stackOutTop];
    //将输出栈中元素放回输入栈中
    while(stackOutTop > 0) {
        obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];
    }
    //更新栈顶指针
    obj->stackInTop = stackInTop;
    obj->stackOutTop = stackOutTop;
    //返回队列中第一个元素
    return top;
}

int myQueuePeek(MyQueue* obj) {
    int res = myQueuePop(obj);
    myQueuePush(obj, res);
    return res;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stackInTop == 0 && obj->stackOutTop == 0;
}

void myQueueFree(MyQueue* obj) {
    obj->stackInTop = 0;
    obj->stackOutTop = 0;
}


int main(void)
{
    MyQueue* obj = myQueueCreate();
    myQueuePush(obj, 3);
    myQueuePush(obj, 5);
    int param_3 = myQueuePeek(obj);
    int param_2 = myQueuePop(obj);
    bool param_4 = myQueueEmpty(obj);
    myQueueFree(obj);
    return 0;
}
