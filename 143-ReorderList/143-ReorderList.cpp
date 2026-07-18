// Last updated: 7/18/2026, 2:06:02 PM

class Solution {

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* nextelement = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextelement;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* first = head;
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;
        while (second) {
            ListNode* temp = first->next;
            ListNode* prevTemp = second->next;

            first->next = second;
            second->next = temp;
            first = temp;
            second = prevTemp;
        }
    }
};