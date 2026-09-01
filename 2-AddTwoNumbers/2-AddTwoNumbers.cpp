// Last updated: 9/1/2026, 11:38:16 PM
1
2class Solution {
3public:
4    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
5        ListNode* a = l1;
6        ListNode* b = l2;
7        int carry = 0;
8        ListNode* dummy = new ListNode(-1);
9        ListNode* nHead = dummy;
10        while (a != NULL && b != NULL) {
11            int total = a->val + b->val + carry;
12            carry = total / 10;
13            int digit = total % 10;
14            ListNode* temp = new ListNode(digit);
15            dummy->next = temp;
16            dummy = temp;
17            a = a->next;
18            b = b->next;
19        }
20        while (a != NULL) {
21            int total = a->val + carry;
22            carry = total / 10;
23            int digit = total % 10;
24            ListNode* temp = new ListNode(digit);
25            dummy->next = temp;
26            dummy = temp;
27            a = a->next;
28        }
29        while (b != NULL) {
30            int total = b->val + carry;
31            carry = total / 10;
32            int digit = total % 10;
33            ListNode* temp = new ListNode(digit);
34            dummy->next = temp;
35            dummy = temp;
36            b = b->next;
37        }
38        if (carry) {
39            ListNode* temp = new ListNode(carry);
40            dummy->next = temp;
41            dummy = temp;
42        }
43        return nHead->next;
44    }
45};