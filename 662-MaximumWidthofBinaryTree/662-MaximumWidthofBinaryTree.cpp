// Last updated: 9/8/2026, 6:35:08 PM
1
2class Solution {
3public:
4    int widthOfBinaryTree(TreeNode* root) {
5        queue<pair<TreeNode*, long long>> q;
6        q.push({root, 0});
7        long long ans = 0;
8        while (!q.empty()) {
9            long long size = q.size();
10            long long first = 0;
11            long long last = 0;
12            long long minind = q.front().second;
13            for (int i = 0; i < size; i++) {
14                auto it = q.front();
15                q.pop();
16                auto node = it.first;
17                long long currind = it.second - minind;
18                if (i == 0)
19                    first = currind;
20                if (i == size - 1)
21                    last = currind;
22                if (node->left != NULL) {
23                    q.push({node->left, 2 * currind + 1});
24                }
25                if (node->right != NULL) {
26                    q.push({node->right, 2 * currind + 2});
27                }
28            }
29            ans = max(ans, abs(last - first) + 1);
30        }
31        return (int)ans;
32    }
33};