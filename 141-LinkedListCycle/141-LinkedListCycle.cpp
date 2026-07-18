// Last updated: 7/18/2026, 2:06:03 PM
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;
        if (head->next == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};