// Last updated: 8/18/2026, 3:20:35 PM
1
2class Solution {
3    ListNode* reverse(ListNode* head) {
4        ListNode* prev = NULL;
5        ListNode* curr = head;
6        while (curr != NULL) {
7            ListNode* nextNode = curr->next;
8            curr->next = prev;
9            prev = curr;
10            curr = nextNode;
11        }
12        return prev;
13    }
14
15public:
16    ListNode* reverseBetween(ListNode* head, int left, int right) {
17
18        ListNode* temp = head;
19        ListNode* leftt = NULL;
20        ListNode* rightt = NULL;
21        ListNode* leftprev = NULL;
22        ListNode* rightNext = NULL;
23
24        int pos = 1;
25
26        while (temp != NULL) {
27            if (pos == left)
28                break;
29
30            leftprev = temp;
31            temp = temp->next;
32            pos++;
33        }
34
35        leftt = temp;
36
37        temp = head;
38        pos = 1;
39
40        while (temp != NULL) {
41            if (pos == right)
42                break;
43
44            temp = temp->next;
45            pos++;
46        }
47
48        rightt = temp;
49        rightNext = temp->next;
50        if (leftprev != NULL)
51            leftprev->next = NULL;
52        rightt->next = NULL;
53
54        ListNode* revHead = reverse(leftt);
55        if (leftprev != NULL)
56            leftprev->next = revHead;
57            else head =revHead;
58        leftt->next = rightNext;
59
60        return head;
61    }
62};