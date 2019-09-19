/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (30.97%)
 * Total Accepted:    40.4K
 * Total Submissions: 130.4K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        bool search_end = false;
        int idx = s.size() - 1;
        int n = 0;
        while (!search_end) {
            if (idx < 0 || (s[idx] == ' ' && n > 0)) {
                search_end = true;
            } else if (s[idx] != ' ') {
                ++n;
                --idx;
            } else {
                --idx;
            }
        }
        return n;
    }
};

