// Last updated: 9/13/2026, 2:31:56 PM
1class Solution {
2public:
3    Node* connect(Node* root) {
4        if (!root)
5            return root;
6        queue<Node*> q;
7        q.push(root);
8        while (!q.empty()) {
9            auto size = q.size();
10           Node* prev = NULL;
11            while (size--) {
12                auto node = q.front();
13                q.pop();
14              if(prev)prev->next = node;
15              prev = node;
16                if (node->left)
17                    q.push(node->left);
18                if (node->right)
19                    q.push(node->right);
20            }
21          prev->next = NULL;
22        }
23        return root;
24    }
25};