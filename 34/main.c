#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(void)
{
    printf("Hello, from 34!\n");
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    int sym = 0;
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