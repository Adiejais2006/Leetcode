// Last updated: 7/18/2026, 2:01:02 PM
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL; 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }  

        prev->next = slow->next;
        slow->next = NULL;
        return head;      
    }
};