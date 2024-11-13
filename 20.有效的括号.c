/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
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

bool isValid(char* s) {
    StackNode* stack = createStack();
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            push(&stack, ')');
        } else if (s[i] == '[') {
            push(&stack, ']');
        } else if (s[i] == '{') {
            push(&stack, '}');
        } else if (stack == NULL || s[i] != peek(stack)) {
            return false;
        } else {
            pop(&stack);
        }
    }
    bool result = (stack == NULL);
    while (stack != NULL) {
        pop(&stack);
    }
    return result;
}
// @lc code=end

