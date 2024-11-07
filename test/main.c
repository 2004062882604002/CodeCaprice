#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[100000];
    scanf("%s", str);
    int len = strlen(str);
    int count = 0;
    // 统计字符串中的数字字符个数
    for(int i = 0; i < len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            count++;
    }

    // 最后result的长度
    int newlength = len + 5 * count;
    int newindex = newlength - 1;
    if(newlength > 100000)
        return 0;
    // 确保为‘0’结尾
    str[newlength] = ' ';
    
    for(int i = len - 1; i >= 0; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')  // 判断是数字字符
        {
            str[newindex-- ] = 'r';
            str[newindex-- ] = 'e';
            str[newindex-- ] = 'b';
            str[newindex-- ] = 'm';
            str[newindex-- ] = 'u';
            str[newindex-- ] = 'n';
        }
        else
        {
            str[newindex--] = str[i];
        }
    }
    printf("%s", str);
    return 0;
}