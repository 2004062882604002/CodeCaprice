/*
 * @lc app=leetcode.cn id=150 lang=c
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
// 一直是两个数在做运算，没有遇到 + - * / 就存储，遇到了就是最近两个值做运算

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

int evalRPN(char** tokens, int tokensSize) {
    StackNode* stack = (StackNode* )malloc(sizeof(StackNode));
    stack = createStack();
    int num1, num2;
    for(int i = 0; i < tokensSize; i++)
    {
        // if(tokens[i] == "+")，有问题
        //在 C 语言中，字符串比较应该使用 strcmp 而不是 ==。== 只是比较指针是否相等，而不是字符串内容
        if(strcmp(tokens[i], "+") == 0)
        {
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, num2 + num1);
        }
        else if(strcmp(tokens[i], "-") == 0)
        {
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, num2 - num1);
        }
        else if(strcmp(tokens[i], "*") == 0)
        {
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, num2 * num1);
        }
        else if(strcmp(tokens[i], "/") == 0)
        {
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, num2 / num1);
        }
        else   // 数字
        {
            push(&stack, atoi(tokens[i]));
        }
    }
    return peek(stack);
}
// @lc code=end

