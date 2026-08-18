// Last updated: 8/18/2026, 7:44:32 PM
1class Solution {
2    ListNode* reverse(ListNode* head) {
3        ListNode* prev = NULL;
4        ListNode* cur = head;
5        while (cur != NULL) {
6            ListNode* nextNode = cur->next;
7            cur->next = prev;
8            prev = cur;
9            cur = nextNode;
10        }
11        return prev;
12    }
13public:
14    void reorderList(ListNode* head) {
15        if (head == NULL || head->next == NULL)
16            return;
17        ListNode* slow = head;
18        ListNode* fast = head;
19        while (fast->next != NULL && fast->next->next != NULL) {
20            slow = slow->next;
21            fast = fast->next->next;
22        }
23        ListNode* right = slow->next;
24        slow->next = NULL;
25        right = reverse(right);
26        ListNode* left = head;
27        while (right != NULL) {
28            ListNode* nextLeft = left->next;
29            ListNode* nextRight = right->next;
30            left->next = right;
31            right->next = nextLeft;
32            left = nextLeft;
33            right = nextRight;
34        }
35    }
36};