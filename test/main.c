#include <stdio.h>
#include "uthash.h"

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
    while(1)
    {
        // 查找是否重复
        HASH_FIND_INT(set, &num, ras);
        if(ras)
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

int main(void)
{
    int n;
    isHappy(n);
    printf("%d", get_sum(n));
    return 0;
}


struct hashTable
{
    int key;            // 存储在哈希表里面的id，一般数字直接用就行
    UT_hash_handle hh; // 初学者不管，有就行
};

void fun()
{
    typedef struct hashTable hashTable; // 我比较喜欢先“重命名”，这样下面使用就比较方便
    // 创建哈希表
    hashTable* user = NULL;
    // 一般最少还要创建一个以作使用，但是这个先不急赋值,一般会在下面先判断是否在哈希表里面再选择插入
    hashTable* num;
    // 调用查找函数
    int test = 4;
    HASH_FIND_INT(set, &test, num);  // set: 哈希表；&test 查找的数据，指针结构所以要取地址；num 当前数据查找的指针如果存在就会返回地址
    if(num == NULL)  //如果不存在，则地址为空
    {
        // 调用插入函数
        num = (hashTable* )malloc(sizeof(hashTable));  // 动态分配空间
        num->key = num;   // 将id在哈希表里确定
        HASH_ADD_INT(set, key, num);  // 插入
        del(set, num); // 删除
    }
}