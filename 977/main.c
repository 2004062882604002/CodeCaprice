#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize);
int main(void)
{
    int nums[5] = {-4,-1,0,3,10};
    int * new;
    new = sortedSquares(nums,5, new);
    for(int i = 0; i < 5; i++)
    {
        printf("%d", new[i]);
    }
    printf("Hello, from 977!\n");
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int k = numsSize - 1;
    int *result = (int *)malloc(sizeof(int) * numsSize);

    for(int i = 0, j = numsSize - 1; i <= j; )
    {
        if(nums[j] * nums[j] > nums[i] * nums[i])
        {
            result[k--] = nums[j] * nums[j];
            j--;
        }
        else
        {
            result[k--] = nums[i] * nums[i];
            i++;
        }
    }
    return result;
}