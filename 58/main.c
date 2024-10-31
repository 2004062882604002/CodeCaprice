#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length = 0;
    int sum = 0;
    scanf("%d", &length);
    int* arr = (int* )malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(1)
    {
        int begin, end;
        scanf("%d %d", &begin, &end);
        for(int i = begin; i < end + 1; i++)
        {
            sum = sum + arr[i];
        }
        printf("%d", sum);
    }
    return 0;
}