// Last updated: 9/13/2026, 2:49:05 PM
1class Solution {
2public:
3    Node* connect(Node* root) {
4        Node* curr = root;
5        while (curr) {
6            Node* dummy = new Node(0);
7            Node* tail = dummy;
8            while (curr) {
9                if (curr->left) {
10                    tail->next = curr->left;
11                    tail = tail->next;
12                }
13                if (curr->right) {
14                    tail->next = curr->right;
15                    tail = tail->next;
16                }
17                curr = curr->next;
18            }
19            curr = dummy->next;
20        }
21        return root;
22    }
23};