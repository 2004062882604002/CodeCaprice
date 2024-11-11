#include <stdio.h>
#include <string.h>

// 无法确定单词个数以及总单词字母数
char* reverseWords(char* s);
int main(void)
{
    char str[50];
    gets(str);
    reverseWords(str);
    printf("Hello, from 151!\n");
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int index = 0;
    int newlen, num_word, num;
    for(int i = 0; i < len; i++)
    {
        // 找到单词
        if(s[index] >= 'a' && s[index] <= 'z') // i + 1小心越界
        {
            num++;
            if(s[index + 1] == ' ')
                num_word++;
        }
        index++;
    }
    return s;
}