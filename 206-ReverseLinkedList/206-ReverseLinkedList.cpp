// Last updated: 8/18/2026, 2:50:36 PM
1
2class Solution {
3public:
4    ListNode* reverseList(ListNode* head) {
5        ListNode* prev = NULL;
6        ListNode* curr = head;
7        while (curr != NULL) {
8            ListNode* nextNode = curr->next;
9            curr->next = prev;
10            prev = curr;
11            curr = nextNode;
12        }
13        return prev;
14    }
15};