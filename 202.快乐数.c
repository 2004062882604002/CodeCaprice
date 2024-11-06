/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 */

// @lc code=start
struct hashTable{
    int key;
    UT_hash_handle hh;
};

int get_sum(int n)
{
    int sum = 0;
    int rem = 0;
    while(n != 0)
    {
        rem = n % 10;
        n = n / 10;
        sum = sum +  rem * rem;
    }
    return sum;
}
bool isHappy(int n) {
   typedef struct hashTable hashTable;
    // 定义哈希表
    hashTable* set = NULL;
    hashTable* ras;
    int num = get_sum(n);
    while(num != 1)
    {
        // 查找是否重复
        HASH_FIND_INT(set, &num, ras);
        if(ras != NULL)
            return false;
        else  // 如果没查找到就要插入
        {
            ras = (hashTable* )malloc(sizeof(hashTable));
            ras->key = num;
            HASH_ADD_INT(set, key, ras);
            num = get_sum(num);
        }
    }
    return true; 
}
// @lc code=end

