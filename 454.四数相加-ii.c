/*
 * @lc app=leetcode.cn id=454 lang=c
 *
 * [454] 四数相加 II
 */

// @lc code=start
struct hashTable{
    int value;
    int key;
    UT_hash_handle hh;
};
int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
    typedef struct hashTable hashTable;
    // 创建哈希表
    hashTable* user1 = NULL;
    hashTable* SUM1;
    // 两个数组的和的映射
    int sum1;
    for(int i = 0; i < nums1Size; i++)
    {
        for(int j = 0; j < nums2Size; j++)
        {
            sum1 = nums1[i] + nums2[j];
            // 查找是否存在过
            HASH_FIND_INT(user1, &sum1, SUM1);
            if(SUM1 == NULL)
            {
                SUM1 = (hashTable* )malloc(sizeof(hashTable));
                SUM1->key = sum1;
                SUM1->value = 1;
                HASH_ADD_INT(user1, key, SUM1);
            }
            else
            {
                SUM1->value++;
            }
        }
    }
    int target;
    int result = 0;
    for(int i = 0; i < nums3Size; i++)
    {
        for(int j = 0; j < nums4Size; j++)
        {
            target = -(nums3[i] + nums4[j]);
            HASH_FIND_INT(user1, &target, SUM1);
            if(SUM1 != NULL)
            {
                result = (SUM1->value) + result;
            }
        }
    }
    
    return result;
}
// @lc code=end

