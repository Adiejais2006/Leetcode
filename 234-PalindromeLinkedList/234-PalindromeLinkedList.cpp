// Last updated: 9/1/2026, 10:59:35 PM
1class Solution {
2public:
3    bool isPalindrome(ListNode* head) {
4        vector<int> ans;
5        ListNode* temp = head;
6        while(temp!=NULL){
7            ans.push_back(temp->val);
8            temp =  temp->next;
9        }
10        int i = 0 ;
11        int j = ans.size()-1;
12
13        while(i<j){
14            if(ans[i++]!=ans[j--]) return false;
15        }
16
17        return true;
18    }
19};