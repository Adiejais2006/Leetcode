// Last updated: 9/1/2026, 7:51:06 PM
1class Solution {
2public:
3    ListNode* detectCycle(ListNode* head) {
4        ListNode* slow = head;
5        ListNode* fast = head;
6        while (fast != NULL && fast->next != NULL) {
7            slow = slow->next;
8            fast = fast->next->next;
9            if (fast == slow)
10                break;
11        }
12        if (fast == NULL || fast->next == NULL)
13            return NULL;
14        ListNode* temp = head;
15        while (temp != slow) {
16            slow = slow->next;
17            temp = temp->next;
18        }
19        return temp;
20    }
21};