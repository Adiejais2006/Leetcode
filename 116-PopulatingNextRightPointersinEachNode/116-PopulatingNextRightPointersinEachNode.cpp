// Last updated: 9/13/2026, 2:15:38 PM
1class Solution {
2public:
3    Node* connect(Node* root) {
4        if (!root)
5            return root;
6        Node* start = root;
7        while (start->left) {
8            Node* curr = start;
9            while (curr) {
10                curr->left->next = curr->right;
11                if (curr->next)
12                    curr->right->next = curr->next->left;
13
14                curr = curr->next;
15            }
16            start = start->left;
17        }
18        return root;
19    }
20};