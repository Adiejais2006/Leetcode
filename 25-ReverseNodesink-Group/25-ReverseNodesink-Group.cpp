// Last updated: 8/31/2026, 7:24:47 PM
1class Solution {
2
3    ListNode* reverse(ListNode* head) {
4        ListNode* prev = NULL;
5        ListNode* temp = head;
6        while (temp != NULL) {
7            ListNode* nextNode = temp->next;
8            temp->next = prev;
9            prev = temp;
10            temp = nextNode;
11        }
12        return prev;
13    }
14
15public:
16
17    ListNode* reverseKGroup(ListNode* head, int k) {
18        ListNode* start = head;
19        ListNode* end = head;
20        ListNode* prev = NULL;
21        int cnt = 1;
22        while (end != NULL) {
23            while (end != NULL && cnt % k != 0) {
24                cnt++;
25                end = end->next;
26            }
27            if (end != NULL && cnt % k == 0) {
28                ListNode* endNext = end->next;
29                end->next = NULL;
30                ListNode* reversedHead = reverse(start);
31                if (prev != NULL)
32                    prev->next = reversedHead;
33                else
34                    head = reversedHead;
35                prev = start;
36                start->next = endNext;
37                start = endNext;
38                end = endNext;
39                cnt = 1;
40            }
41        }
42
43        return head;
44    }
45};