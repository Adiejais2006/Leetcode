// Last updated: 10/23/2026, 12:48:05 PM
1
2class Solution {
3public:
4    int deepestLeavesSum(TreeNode* root) {
5        int sum = 0;
6        queue<TreeNode*> q;
7        q.push(root);
8        int ans = 0;
9        while (!q.empty()) {
10            int size = q.size();
11            sum = 0;
12            for (int i = 0; i< size; i++) {
13                auto a = q.front();
14                q.pop();
15                sum += a->val;
16                if (a->left) {
17                    q.push(a->left);
18                }
19                if (a->right) {
20                    q.push(a->right);
21                }
22            }
23        }
24        return sum;
25    }
26};