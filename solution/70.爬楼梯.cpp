/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (46.59%)
 * Total Accepted:    76K
 * Total Submissions: 163K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶  1 + 1
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶   2 + 1
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 输入：4
 * 输出：5
 * 1. 1 + 1 + 1 + 1      3 + 1 + 1
 * 2. 1 + 1 + 2
 * 3. 1 + 2 + 1
 * 4. 2 + 1 + 1
 * 5. 2 + 2
 * 
 * 输入：5
 * 输出：8
 * 1. 1 + 1 + 1 + 1 + 1    4 + (2+1) + 1
 * 
 * 12
 * 13
 * 1. 1 + 1 + 1 + 1 + 1 + 1    5 + (6) + 1 + 1
 */
#include <iostream>
#include <cstdio>

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        int i = 2;
        int a = 1;
        int b = 2;

        while (i < n) {
            b = a + b;
            a = b - a;
            ++i;
        }

        return b;
    }
};

// int main(int argc, char* argv[]) {
//     Solution st;
//     int n = 0;
//     sscanf(argv[1], "%d", &n);
//     int ways = st.climbStairs(n);
//     std::cout << ways << std::endl;
// }

