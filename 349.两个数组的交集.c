/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hash[1005] = {0};
    int* result = (int* )calloc(nums1Size < nums2Size ? nums1Size : nums2Size,sizeof(int));
    int relindex = 0;
    for(int i = 0; i < nums1Size; i++)
    {
        hash[nums1[i]]++;
    }
    for(int i = 0;i <nums2Size; i++)
    {
        if(hash[nums2[i]] > 0)
        {
            result[relindex] = nums2[i];
            relindex++;
            hash[nums2[i]] = 0;
        }
    }
    * returnSize = relindex;
    return result;
}
// @lc code=end

