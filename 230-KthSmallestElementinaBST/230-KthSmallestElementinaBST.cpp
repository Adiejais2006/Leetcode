// Last updated: 9/6/2026, 7:04:05 PM
1
2class Solution {
3    void rank(TreeNode* root, int& k, int& ans) {
4        if (root == NULL)
5            return;
6        rank(root->left, k, ans);
7        k--;
8        if (k == 0) {
9            ans = root->val;
10            return;
11        }
12        rank(root->right, k, ans);
13    }
14
15public:
16    int kthSmallest(TreeNode* root, int k) {
17        int ans = 0;
18        rank(root, k, ans);
19        return ans;
20    }
21};