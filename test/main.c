#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char arr[10000];
    char num[7] = "number";
    if (scanf("%s", arr) != 1) {
        fprintf(stderr, "Input error\n");
        return 1;
    }
    size_t slow = 0;
    char* result = (char*)malloc(sizeof(char) * (strlen(arr) * 6 + 1));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (size_t i = 0; i < strlen(arr); i++)
    {
        if ((int)arr[i] >= 48 && (int)arr[i] <= 57) // 数字的ASCII
        {
            strncpy(result + slow, num, 6);
            slow += 6;
        }
        else
        {
            result[slow++] = arr[i];
        }
    }
    result[slow] = '\0'; // 确保结果字符串以空字符结尾

    printf("%s", result);

    free(result); // 释放动态分配的内存
    return 0;
}