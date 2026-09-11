// Last updated: 9/11/2026, 3:37:43 PM
1class Solution {
2public:
3    bool isCousins(TreeNode* root, int x, int y) {
4        queue<pair<TreeNode*, TreeNode*>> q;
5        q.push({root, nullptr});
6        while (!q.empty()) {
7            int size = q.size();
8            TreeNode* parentX = nullptr;
9            TreeNode* parentY = nullptr;
10            while (size--) {
11                auto [node, parent] = q.front();
12                q.pop();
13                if (node->val == x)
14                    parentX = parent;
15                if (node->val == y)
16                    parentY = parent;
17                if (node->left)
18                    q.push({node->left, node});
19                if (node->right)
20                    q.push({node->right, node});
21            }
22            if (parentX && parentY)
23                return parentX != parentY;
24            if (parentX || parentY)
25                return false;
26        }
27        return false;
28    }
29};