#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将字符串存储进栈里面，并且判断如果和栈顶top相同则不存储，否则存储
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

char* removeDuplicates(char* s) {
    StackNode* stack = createStack();
    int index = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] != (char)peek(stack))
        {
            push(&stack, s[i]);
            index++;
        } 
        else
        {
            pop(&stack);
            index--;
        }  
    }
    char* arr = (char* )malloc(sizeof(char) * (index + 1));
    for(int i = 0; i < index + 1; i++)
    {
        arr[i] = (char)pop(&stack);
    }
    arr[index] = '\0';
    int left = 0;
    int right = index - 1;
    while(left < right)
    {
        char temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
        left++;
        right--;
    }
    return arr;
}

int main() {
    char* test_strings[] = {
        "aabbcc",
        "abbaca",
        "hello",
        "mississippi",
        "aabbcdeffg"
    };

    for (int i = 0; i < 5; i++) {
        char* result = removeDuplicates(test_strings[i]);
        printf("Original: %s, Without Duplicates: %s\n", test_strings[i], result);
        free(result);  // Free the allocated memory
    }

    return 0;
}