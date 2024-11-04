/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
bool isAnagram(char* s, char* t) {
    int hash[26] = {0};
    for(int i = 0; i < strlen(s); i++)
    {
        hash[s[i] - 'a']++;
    }
    for(int i = 0; i < strlen(t); i++)
    {
        hash[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] != 0)
            return false;
    }
    return true;
}
// @lc code=end

