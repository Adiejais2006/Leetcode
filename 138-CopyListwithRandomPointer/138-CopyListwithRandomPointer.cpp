// Last updated: 8/31/2026, 9:33:22 PM
1class Solution {
2public:
3    Node* copyRandomList(Node* head) {
4        Node* dummy = new Node(-1);
5        Node* headBefore = dummy;
6        Node* temp = head;
7        unordered_map< Node* , Node*> mpp;
8        while (temp != NULL) {
9            Node* newNode = new Node(temp->val);
10            mpp[temp] = newNode;
11            dummy->next = newNode;
12            dummy = newNode;
13            temp = temp->next;
14        }
15        temp = head;
16        Node* copyTemp = headBefore->next;
17        while (temp != NULL) {
18            copyTemp->random = mpp[temp->random];
19            temp = temp->next;
20            copyTemp = copyTemp->next;
21        }
22        return headBefore->next;
23    }
24};