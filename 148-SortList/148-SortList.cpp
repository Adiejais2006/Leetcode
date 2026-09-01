// Last updated: 9/1/2026, 12:03:22 PM
1
2class Solution {
3public:
4    ListNode* sortList(ListNode* head) {
5        vector<int> ans;
6        ListNode* temp = head;
7        while(temp!=NULL){
8            ans.push_back(temp->val);
9            temp = temp->next;
10        }
11        sort(ans.begin() , ans.end());
12        int i = 0 ;
13        temp = head;
14        while(temp!=NULL){
15            temp->val = ans[i++];
16            temp = temp->next;
17        }
18        return head;
19    }
20};