// Last updated: 9/2/2026, 1:06:46 AM
1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        if (head == NULL || head->next == NULL)
5            return head;
6        ListNode* temp = head;
7        int n = 0;
8        while (temp != NULL) {
9            n++;
10            temp = temp->next;
11        }
12        k = k % n;
13        if (k == 0)
14            return head;
15        temp = head;
16        for (int i = 1; i < n - k; i++) {
17            temp = temp->next;
18        }
19        ListNode* newHead = temp->next;
20        temp->next=NULL;
21        ListNode* temp2 = newHead;
22        while(temp2->next!=NULL)temp2=temp2->next;
23        temp2->next = head;
24        return newHead;
25    }
26};