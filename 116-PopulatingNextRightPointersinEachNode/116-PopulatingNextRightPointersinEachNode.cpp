// Last updated: 9/13/2026, 12:34:24 PM
1class Solution {
2public:
3    Node* connect(Node* root) {
4        if (!root)
5            return root;
6        queue<Node*> q;
7        q.push(root);
8        while (!q.empty()) {
9            auto size = q.size();
10            vector<Node*> a;
11            while (size--) {
12                auto node = q.front();
13                q.pop();
14                a.push_back(node);
15                if (node->left)
16                    q.push(node->left);
17                if (node->right)
18                    q.push(node->right);
19            }
20            int i = 1;
21            int n = a.size();
22            while (i < n) {
23                a[i - 1]->next = a[i];
24                i++;
25            }
26            a[n - 1]->next = NULL;
27        }
28        return root;
29    }
30};