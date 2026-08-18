// Last updated: 8/18/2026, 3:17:22 PM
1class Solution {
2    ListNode* reverse(ListNode* head) {
3        ListNode* prev = NULL;
4        ListNode* curr = head;
5        while (curr != NULL) {
6            ListNode* nextNode = curr->next;
7            curr->next = prev;
8            prev = curr;
9            curr = nextNode;
10        }
11        return prev;
12    }
13
14public:
15    ListNode* reverseBetween(ListNode* head, int left, int right) {
16        ListNode* temp = head;
17        ListNode* leftt = NULL;
18        ListNode* rightt = NULL;
19        ListNode* leftprev = NULL;
20        ListNode* rightNext = NULL;
21        int pos = 1;
22        while (temp != NULL) {
23            if (pos == left)
24                break;
25            leftprev = temp;
26            temp = temp->next;
27            pos++;
28        }
29        leftt = temp;
30        temp = head;
31        pos = 1;
32        while (temp != NULL) {
33            if (pos == right)
34                break;
35            temp = temp->next;
36            pos++;
37        }
38        rightt = temp;
39        rightNext = temp->next;
40        if (leftprev != NULL)
41            leftprev->next = NULL;
42        rightt->next = NULL;
43        ListNode* revHead = reverse(leftt);
44        if (leftprev != NULL)
45            leftprev->next = revHead;
46        else
47            head = revHead;
48        leftt->next = rightNext;
49        return head;
50    }
51};