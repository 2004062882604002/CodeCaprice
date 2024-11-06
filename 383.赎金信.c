/*
 * @lc app=leetcode.cn id=383 lang=c
 *
 * [383] 赎金信
 */

// @lc code=start
struct hashTable{
    int key;
    int value;
    UT_hash_handle hh;
};
bool canConstruct(char* ransomNote, char* magazine) {
    typedef struct hashTable hashTable;
    hashTable* user = NULL;
    hashTable* str1;
    int num1, num2;
    for(int i = 0; i < strlen(ransomNote); i++)
    {
        num1 = ransomNote[i] - 'a';
        HASH_FIND_INT(user, &num1, str1);
        if(str1 == NULL)
        {
            str1 = (hashTable* )malloc(sizeof(hashTable));
            str1->key = num1;
            str1->value = 1;
            HASH_ADD_INT(user, key, str1);
        }
        else 
        {
            str1->value++;
        }
    }
    for(int i = 0; i < strlen(magazine); i++)
    {
        num2 = magazine[i] - 'a';
        HASH_FIND_INT(user, &num2, str1);
        if(str1 != NULL)
        {
            str1->value--;
            if(str1->value == 0)
                HASH_DEL(user, str1);
        }

    }
    if(HASH_COUNT(user) != 0)
        return false;
    else
        return true;
}
// @lc code=end

