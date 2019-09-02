/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.62%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    115.9K
 * Total Submissions: 334.8K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n <= 0) {
            return "";
        }
        int m = strs[0].size();
        int common_prefix_idx = -1;
        bool find_end = false;

        while (!find_end) {
            if (m == 0) {
                find_end = true;
            } else {
                for (int i = 0; i < m && !find_end; ++i) {
                    char c1 = strs[0][i];
                    for (int j = 1; j < n && !find_end; ++j) {
                        if (!(strs[j].size() > i && strs[j][i] == c1)) {
                            find_end = true;
                        }
                    }
                    if (!find_end) {
                        ++common_prefix_idx;
                    }
                    if (i == m - 1) {
                        find_end = true;
                    }
                }
            }
        }

        if (common_prefix_idx == -1) {
            return "";
        } else {
            return strs[0].substr(0, common_prefix_idx + 1);
        }
    }
};

