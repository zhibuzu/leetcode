/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (34.62%)
 * Total Accepted:    12.7K
 * Total Submissions: 36.5K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
#include <iostream>
#include <string>
#include <cstdio>

using std::string;

class Solution {
public:
    string convertToTitle(int n) {
        int remind = 0;
        string s;
        while (n > 0) {
            remind = n % 26;
            n = (n-1) / 26;
            s = convertToChar(remind) + s;
        }
        return s;
    }

    char convertToChar(int n) {
        if (n < 1 || n > 26) {
            return 'Z';
        }

        return n + 64;
    }
};

// int main(int argc, char* argv[]) {
//     int n = atoi(argv[1]);
//     std::cout << "input n:" << n << std::endl;

//     Solution ss;
//     char c = ss.convertToChar(n);
//     std::cout << "output char:" << c << std::endl;

//     string res = ss.convertToTitle(n);
//     std::cout << "output res:" << res << std::endl;
// }

