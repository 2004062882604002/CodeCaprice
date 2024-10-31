#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length = 0;
    int sum = 0;
    scanf("%d", &length);
    int* arr = (int* )malloc(sizeof(int) * (length + 1));
    arr[0] = 0;
    for(int i = 1; i < length + 1; i++)
    {
        int num;
        scanf("%d", &num);
        arr[i] = arr[i - 1] + num;
    }

    int begin, end;
    while(scanf("%d %d", &begin, &end) == 2)
    {
        sum = arr[end + 1] - arr[begin];
        printf("%d\n", sum);
    }
    free(arr);
    return 0;
}