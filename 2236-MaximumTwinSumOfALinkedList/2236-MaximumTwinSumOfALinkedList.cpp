// Last updated: 7/18/2026, 2:00:58 PM

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // middle tak pahuchp
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        int ans = INT_MIN;
        ListNode* prev = NULL;
        // middle ke baad walo ko reverse jr diya
         // ab bas ans nikal diya prev aur head statr se 
        // pehle aisa tha 5->4->2->1
        // ab aisa ho jayega  5->4  NULL<-2<-1
        // first hoga 5 pr aur second hoga 1 pr to ans aayega
        // 5+1 , then 4 + 2 to ans 6 aa jayega
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
       
        ListNode *first = head, *second = prev;
        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};