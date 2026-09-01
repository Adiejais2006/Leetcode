// Last updated: 9/1/2026, 7:39:48 PM
1class Solution {
2public:
3    bool hasCycle(ListNode* head) {
4        if (!head)
5            return false;
6        ListNode* slow = head;
7        ListNode* fast = head;
8      while (fast != NULL && fast->next != NULL){
9            slow=slow->next;
10            if(fast->next==NULL) return false;
11            fast=fast->next->next;
12            if(slow==fast) return true;
13            
14        }
15        return false;
16    }
17};