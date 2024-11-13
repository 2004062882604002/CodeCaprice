#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s, int start, int end);
int main(void)
{
    int k;
    scanf("%d", &k);
    getchar();
    char s[10000] = {0};
    gets(s);
    
    int length = strlen(s);
    reverse(s, 0, length - 1);
    reverse(s, 0, k - 1);
    reverse(s, k, length - 1);
    printf("%s\n", s);
    return 0;
}

void reverse(char *s, int start, int end)
{
    while(start < end)
    {
        char temp = s[end];
        s[end] = s[start];
        s[start] = temp;
        start++;
        end--;
    }
}