// Last updated: 9/7/2026, 7:26:11 PM
1class Solution {
2    void func(int& cnt, TreeNode* root, int maxu) {
3        if (root == NULL)
4            return;
5        if (maxu <= root->val)
6            cnt++;
7        func(cnt, root->left, max(maxu, root->val));
8        func(cnt, root->right, max(maxu, root->val));
9    }
10
11public:
12    int goodNodes(TreeNode* root) {
13        if (root == NULL)
14            return 0;
15        int cnt = 0;
16        func(cnt, root, INT_MIN);
17        return cnt;
18    }
19};