// Last updated: 9/1/2026, 1:18:21 PM
1
2class Solution {
3
4    ListNode* merger(ListNode*& a, ListNode*& b) {
5        ListNode* dummy = new ListNode(-1);
6        ListNode* dummyHead = dummy;
7        while (a != NULL && b != NULL) {
8            if (a->val >= b->val) {
9                dummy->next = b;
10
11                b = b->next;
12            } else {
13                dummy->next = a;
14
15                a = a->next;
16            }
17            dummy = dummy->next;
18        }
19        while (a != NULL) {
20            dummy->next = a;
21            a=a->next;
22            dummy = dummy->next;
23        }
24        while (b != NULL) {
25            dummy->next = b;
26            b=b->next;
27            dummy = dummy->next;
28        }
29        return dummyHead->next;
30    }
31    ListNode* mergesort(ListNode*& head) {
32        if (head == NULL || head->next == NULL)
33            return head;
34        ListNode* middleNode = mid(head);
35        ListNode* right = middleNode->next;
36        middleNode->next = NULL;
37        ListNode* leftSorted = mergesort(head);
38        ListNode* rightSorted = mergesort(right);
39        return merger(leftSorted, rightSorted);
40    }
41
42    ListNode* mid(ListNode* head) {
43        ListNode* slow = head;
44        ListNode* fast = slow->next;
45        while (fast != NULL && fast->next != NULL) {
46            slow = slow->next;
47            fast = fast->next->next;
48        }
49        return slow;
50    }
51
52public:
53    ListNode* sortList(ListNode* head) {
54        if (head == NULL || head->next == NULL)
55            return head;
56        return mergesort(head);
57    }
58};