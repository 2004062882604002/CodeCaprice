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
    int left = 0;
    int right = numsSize - 1;

    int *ans = (int *)malloc(sizeof(int) * numsSize);
    for(int i = numsSize-1; i > -1; i--)
    {
        if(nums[left] * nums[left] > nums[right] * nums[right])
        {
            ans[i--] = nums[left]*nums[left];
            ans[i] = nums[right]*nums[right];
        }
        else if(nums[left] * nums[left] < nums[right] * nums[right])
        {
            ans[i--] = nums[right]*nums[right];
            ans[i] = nums[left]*nums[left];  
        }
        else
        {
            if(i == 0)
                ans[i] = nums[left]*nums[left];
            else
            {
                ans[i--] = nums[right]*nums[right];
                ans[i] = nums[left]*nums[left];
            } 
        }
        right --;
        left ++;
    }
    return ans;
}