// Last updated: 9/1/2026, 10:43:09 PM
1
2class Solution {
3public:
4    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
5        ListNode* a = headA;
6        ListNode* b = headB;
7        while (a != b) {
8            if (a == NULL)
9                a = headB;
10            else
11                a = a->next;
12            if (b == NULL)
13                b = headA;
14            else
15                b = b->next;
16        }
17        return a;
18    }
19};