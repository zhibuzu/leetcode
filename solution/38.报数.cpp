/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (52.30%)
 * Total Accepted:    45.7K
 * Total Submissions: 87.3K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
#include <cstdio>
#include <string>

using std::string;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s1 = countAndSay(n - 1);
        string s2;
        s2.clear();
        int cursor = 0;
        char base_chr = s1[cursor];
        int cnt = 1;
        char cnt_ss[10] = {0};
        for (int i = 1; i < s1.size(); ++i) {
            if (s1[i] != base_chr) {
                // append to s2
                sprintf(cnt_ss, "%d", cnt);
                s2.append(cnt_ss);
                s2.append(&base_chr, 1);
                cursor = i;
                base_chr = s1[cursor];
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        // append to s2 in end
        sprintf(cnt_ss, "%d", cnt);
        s2.append(cnt_ss);
        s2.append(&base_chr, 1);

        return s2;
    }
};


