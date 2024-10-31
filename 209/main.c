#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize);
int main(void)
{
    return 0;
}

int minSubArrayLen(int target, int* nums, int numsSize) {
    int result = INT_MAX;
    int length = 0;
    for(int begin = 0; begin < numsSize; begin++)
    {
        int sum = 0;
        for(int end = begin; end < numsSize; end++)
        {
            sum = sum + nums[end];
            if(sum >= target)
            {
                length = end - begin + 1;
                result = length < result ? length : result;
                break;
            }
        }
    }
    return result == INT_MAX ? 0 : result;
    
}