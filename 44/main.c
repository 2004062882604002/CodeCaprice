/*
第一行输入两个正整数，代表 n 和 m。 
接下来的 n 行，每行输出 m 个正整数。
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n, m, dif;
    int result = INT_MAX;
    scanf("%d %d", &n, &m);
    int *a = (int* )malloc(sizeof(int) * n);
    int *b = (int* )malloc(sizeof(int) * m);

    // 初始化行
    for(int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    // 初始化列
    for(int j = 0; j < m; j++)
    {
        b[j] = 0;
    }

    // 计算每行每列权重和
    for(int i = 0; i < n; i++)
    {
       for(int j = 0;j < m; j++)
       {
            int mm;
            scanf("%d", &mm); 
            a[i] = a[i] + mm;
            b[j] = b[j] + mm;
       }
    }

    // 求行的前缀和
    for(int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
    // 求l列的前缀和
    for(int j = 1; j < m; j++)
    {
        b[j] = b[j] + b[j - 1];
    }

    // 行差值最小值
    for(int i = 0; i < n - 1; i++)
    {
        dif = abs(a[n - 1] - a[i] - a[i]);
        result = dif < result ? dif : result;
    }
    // 列差值最小值
    for(int j = 0; j < m - 1; j++)
    {
        dif = abs(b[m - 1] - b[j] - b[j]);
        result = dif < result ? dif : result;
    }

    printf("%d", result);
    free(a);
    free(b);
    return 0;
}
