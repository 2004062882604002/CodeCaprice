// 栈 —— 先进后出
// push pop peck creatStack
#include <stdio.h>

typedef struct StackNode{
    int value;
    struct StackNode* next;

}StackNode;

StackNode* creatStack();
void push(StackNode** top, int value);
int pop(StackNode** top);
int peek(StackNode* top);

int main(void)
{
    StackNode* obj;
    obj = creatStack();
    push(&obj, 5);
    push(&obj, 4);
    int test = peek(obj);
    printf("%d", test);
    pop(&obj);

    return 0;
}

StackNode* creatStack()
{
    return NULL;
}

void push(StackNode** top, int value)
{
    StackNode* NewTop = (StackNode* )malloc(sizeof(StackNode));
    NewTop->next = *top;
    NewTop->value = value;
    *top = NewTop;
}

int pop(StackNode** top)
{
    StackNode* temp = (*top)->next;
    int top_value = (*top)->next->value;
    *top = temp;
    return top_value;
}

int peek(StackNode* top)
{
    int top_value = top->value;
    return top_value;
}

// 2.0修改了pop，只要了当前值
typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

StackNode* createStack() {
    return NULL;
}

void push(StackNode** top, int value) {
    StackNode* NewTop = (StackNode*)malloc(sizeof(StackNode));
    NewTop->next = *top;
    NewTop->value = value;
    *top = NewTop;
}

int pop(StackNode** top) {
    if (*top == NULL) {
        return -1;
    }
    StackNode* temp = *top;
    int top_value = temp->value;
    *top = temp->next;
    free(temp);
    return top_value;
}

int peek(StackNode* top) {
    if (top == NULL) {
        // Handle empty stack if needed
        return -1;
    }
    int top_value = top->value;
    return top_value;
}
