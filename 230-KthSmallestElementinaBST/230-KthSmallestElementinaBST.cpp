// Last updated: 11/2/2026, 4:31:09 PM
1class Solution {
2    int ans = 0;
3    int cnt = 0;
4    void preorder(TreeNode* root, int k) {
5        if (root == NULL || cnt >= k)
6            return;
7        preorder(root->left, k);
8        cnt++;
9        if (cnt == k)
10            ans = root->val;
11        preorder(root->right, k);
12    }
13public:
14    int kthSmallest(TreeNode* root, int k) {
15        preorder(root, k);
16        return ans;
17    }
18};