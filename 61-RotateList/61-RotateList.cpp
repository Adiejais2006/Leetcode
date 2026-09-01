// Last updated: 9/2/2026, 1:22:25 AM
1
2class Solution {
3    ListNode* reverse(ListNode* node) {
4        ListNode* temp = node;
5        ListNode* prev = NULL;
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
16    ListNode* rotateRight(ListNode* head, int k) {
17        if (head == NULL || head->next == NULL)
18    return head;
19        ListNode* temp = head;
20        int n = 0;
21        while (temp != NULL) {
22            temp = temp->next;
23            n++;
24        }
25        k = k % n;
26        if (k == 0)
27            return head;
28        ListNode* rHead = reverse(head);
29        temp = rHead;
30        for (int i = 1; i < k; i++) {
31            temp = temp->next;
32        }
33        ListNode* nextNode = temp->next;
34        temp->next = NULL;
35        ListNode* r1 = reverse(rHead);
36        ListNode* r2 =  reverse(nextNode);
37        rHead->next = r2;
38        return r1;
39    }
40};