/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isValid(string s) {
        bool is_valid = true;
        vector<char> vt;
        vt.clear();
        int i = 0;
        while (is_valid && i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                vt.push_back(s[i]);
                ++i;
            } else {
                if (vt.empty()) {
                    is_valid = false;
                } else {
                    if ((vt[vt.size() - 1] == '(' && s[i] == ')') || \
                    (vt[vt.size() - 1] == '[' && s[i] == ']') || \
                    (vt[vt.size() - 1] == '{' && s[i] == '}')) {
                        vt.pop_back();
                        ++i;
                    } else {
                        is_valid = false;
                    }
                }
            }
        }

        is_valid &= vt.empty();

        return is_valid;
    }
};

