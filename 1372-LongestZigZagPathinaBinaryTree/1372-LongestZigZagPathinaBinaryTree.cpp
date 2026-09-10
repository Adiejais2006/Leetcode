// Last updated: 9/11/2026, 12:55:09 AM
1class Solution {
2    int ans = 0;
3    void func(TreeNode* root, int direction, int len) {
4        if (root == NULL)
5            return;
6        ans = max(ans, len);
7        if (direction == -1) {
8            func(root->left, 0, 1);
9            func(root->right, 1, 1);
10            return;
11        }
12        if (direction == 0) {
13            func(root->left, 0, 1);
14            func(root->right, 1, len + 1);
15        }
16        if (direction == 1) {
17            func(root->left, 0, len + 1);
18            func(root->right, 1, 1);
19        }
20    }
21public:
22    int longestZigZag(TreeNode* root) {
23        func(root, -1, 0);
24        return ans;
25    }
26};