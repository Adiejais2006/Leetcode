// Last updated: 7/18/2026, 2:06:04 PM
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        curr = head;
        Node* clone_head = head->next;
        Node* clone_curr = clone_head;
        
        while (curr != nullptr) {
            curr->next = curr->next->next;
            curr = curr->next;
            
            if (clone_curr->next != nullptr) {
                clone_curr->next = clone_curr->next->next;
                clone_curr = clone_curr->next;
            }
        }
        
        return clone_head;
    }
};