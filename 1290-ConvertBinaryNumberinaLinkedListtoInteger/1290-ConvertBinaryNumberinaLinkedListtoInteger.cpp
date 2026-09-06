// Last updated: 9/6/2026, 5:21:30 PM
1class Solution {
2public:
3    int getDecimalValue(ListNode* head) {
4        int res = 0;
5        ListNode* iter = head;
6        while (iter != NULL) {
7            res <<= 1;
8            res |= iter->val;
9            iter = iter->next;
10        }
11        return res;
12    }
13};