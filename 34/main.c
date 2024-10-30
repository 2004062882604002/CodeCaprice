#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(void)
{
    int nums[6] = {5,7,7,8,8,10};
    int *returnSize;

    searchRange(nums, 6, 8, returnSize);
    
    for(int i = 0; i < 2; i++)
    {
        printf("[%d, %d]", returnSize[0], returnSize[1]);
    }
    printf("Hello, from 34!\n");
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    int sym = 0;
    returnSize = (int *)malloc(2 * sizeof(int));
    returnSize[0] = -1;
    returnSize[1] = -1;
    while(left <= right)
    {
        int middle = (right + left) / 2;
        if(target < nums[middle])
        {
            right = middle - 1;
        }
        else if(target > nums[middle])
        {
            left = middle + 1;
        }
        else
        {
            if(sym == 0)
                returnSize[sym++] = middle;
            else
                returnSize[sym] = middle;
        }
    }
    return returnSize;
}