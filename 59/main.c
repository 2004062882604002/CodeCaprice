#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);
int main(void)
{
    printf("Hello, from 59!\n");
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int** ans = (int**)malloc(sizeof(int*) * n);
    for(int i = 0;i < n; i++)
    {
        ans[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int starx = 0;
    int stary = 0;
    int cir = 1;
    int count = 1;
    int ** nums;
    int i, j;
    // 判断转几圈结束
    while(cir <= n / 2)
    {
        for(j = stary; j < n - stary - 1; j++)
        {
            ans[starx][j] = count++;

        }

        for(i = starx; i < n - starx - 1; i++)
        {
            ans[i][j] = count++;
        }

        for(; j > stary; j--)
        {
            ans[i][j] = count++;
        }

        for(; i > starx; i--)
        {
            ans[i][j] = count++;
        }
        
        starx++;
        stary++;
        cir++;
    }
    if(n % 2 == 1)
    {
        ans[n / 2][n / 2] = count;
    }
    return ans;
}