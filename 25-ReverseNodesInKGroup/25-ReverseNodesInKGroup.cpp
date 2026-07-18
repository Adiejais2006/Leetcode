// Last updated: 7/18/2026, 2:07:44 PM
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev_group_end = &dummy;
        curr = head;
        
        while (count >= k) {
            ListNode* group_start = curr;
            ListNode* prev = nullptr;
            
            for (int i = 0; i < k; ++i) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            prev_group_end->next = prev;
            group_start->next = curr;
            prev_group_end = group_start;
            
            count -= k;
        }
        
        return dummy.next;
    }
};