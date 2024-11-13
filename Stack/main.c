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