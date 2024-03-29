/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (38.79%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    77.8K
 * Total Submissions: 200.5K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) {
            return 0;
        }

        bool find_end = false;
        int cursor = 0;
        int first_find_idx = -1; 
        while (!find_end) {
            if (cursor + m > n) {
                find_end = true;
            } else {
                int move_idx = 0;
                find_end = true;
                while (find_end && move_idx < m) {
                    if (haystack[move_idx + cursor] != needle[move_idx]) {
                        find_end = false;
                        ++cursor;
                    } else {
                        ++move_idx;
                    }
                }
                if (find_end) {
                    first_find_idx = cursor;
                }
            }
        }
        return first_find_idx;
    }
};

