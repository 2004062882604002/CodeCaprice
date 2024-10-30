#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);
int removeElement2(int* nums, int numsSize, int val);

int main(void)
{
    int nums[8] = {0,1,2,2,3,0,4,2};
    int res = 0;
    res = removeElement(nums, 8, 2);
    printf("%d", res);
    return 0;
}

int removeElement(int* nums, int numsSize, int val) {
    int sym = 0;
    int length = numsSize;
    for(int i = 0; i < length; i++)
    {
        if(nums[i] == val)
        {
            sym ++;
            for(int j = i; j < length - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            length--;
            i--;
        }
    }
    return length;
}

int removeElement2(int* nums, int numsSize, int val) {
    int slow = 0;
    for(int fast = 0;fast < numsSize; fast++)
    {
        if(val != nums[fast])
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}