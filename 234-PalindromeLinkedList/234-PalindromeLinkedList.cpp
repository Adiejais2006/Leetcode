// Last updated: 9/1/2026, 11:06:12 PM
1class Solution {
2    ListNode* reverse(ListNode* head) {
3        ListNode* temp = head;
4        ListNode* prev = NULL;
5        while (temp != NULL) {
6            ListNode* nextNode = temp->next;
7            temp->next = prev;
8            prev = temp;
9            temp = nextNode;
10        }
11        return prev;
12    }
13
14public:
15    bool isPalindrome(ListNode* head) {
16        ListNode* slow = head;
17        ListNode* fast = head;
18        while (fast != NULL && fast->next != NULL) {
19            slow = slow->next;
20            fast = fast->next->next;
21        }
22        ListNode* reverseHead = reverse(slow);
23        ListNode* temp = head;
24        while (temp != NULL && reverseHead != NULL) {
25            if (temp->val != reverseHead->val)
26                return false;
27            temp = temp->next;
28            reverseHead = reverseHead->next;
29        }
30        return true;
31    }
32};