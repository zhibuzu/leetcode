/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* l3_op = l3;
        int carry_flag = 0;
        while (l1 != NULL || l2 != NULL) {
            int tmp = carry_flag;
            carry_flag = 0;
            if (l1 != NULL) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                tmp += l2->val;
                l2 = l2->next;
            }
            if (tmp > 9) {
                carry_flag = 1;
                tmp -= 10; 
            }
            l3_op->val = tmp;
            if (l1 != NULL || l2 != NULL || carry_flag == 1) {
                l3_op->next = new ListNode(0);
                l3_op = l3_op->next;
            }
        }
        if (carry_flag == 1) {
            l3_op->val = carry_flag;
        }

        return l3;
    }
};

