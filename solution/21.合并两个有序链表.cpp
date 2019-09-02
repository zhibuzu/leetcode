/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.88%)
 * Total Accepted:    104.4K
 * Total Submissions: 183.5K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode* l3 = new ListNode(0);
        ListNode* l3_tmp = l3;
        ListNode* move_node = NULL;
        while (l1 != NULL || l2 != NULL) {
            move_node = NULL;
            if (l1 != NULL) {
                move_node = l1;
            }
            if (l2 != NULL && (move_node == NULL || move_node->val > l2->val)) {
                move_node = l2;
                l2 = l2->next;
            } else {
                l1 = l1->next;
            }
            l3_tmp->val = move_node->val;
            if (l1 != NULL || l2 != NULL) {
                l3_tmp->next = new ListNode(0);
                l3_tmp = l3_tmp->next;
            }
        }
        return l3;
    }
};

