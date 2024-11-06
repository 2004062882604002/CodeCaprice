// 类似于set实现
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct hashTable
 {
    int key;
    UT_hash_handle hh;
 };
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    typedef struct hashTable hashTable;
    hashTable* set = NULL;  // 创建哈希表
    hashTable* num;
    int* result = (int* )malloc(sizeof(int) * (nums1Size > nums2Size ? nums2Size : nums1Size)); // 创建结果数组
    int index = 0;
    for(int i = 0; i < nums1Size; i++)
    {
        HASH_FIND_INT(set, &nums1[i], num);
        if(num == NULL)
        {
            num = (hashTable* )malloc(sizeof(hashTable));
            num->key = nums1[i];
            HASH_ADD_INT(set, key, num);
        }
    }
    for(int i = 0; i < nums2Size; i++)
    {
        HASH_FIND_INT(set, &nums2[i], num);
        if(num != NULL)
        {
            result[index] = nums2[i];
            index++;
            HASH_DEL(set, num);
        }
    }
    *returnSize = index;
    return result;
}