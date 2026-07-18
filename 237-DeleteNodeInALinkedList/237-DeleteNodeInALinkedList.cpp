// Last updated: 7/18/2026, 2:05:13 PM
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};