// Last updated: 9/8/2026, 11:31:45 PM
1class Solution {
2    int cameras = 0;
3    int dfs(TreeNode* root) {
4        if (root == NULL)
5            return 2; 
6        int left = dfs(root->left);
7        int right = dfs(root->right);
8        if (left == 0 || right == 0) {
9            cameras++;
10            return 1;
11        }
12        if (left == 1 || right == 1) {
13            return 2; // COVERED
14        }
15        return 0;
16    }
17public:
18    int minCameraCover(TreeNode* root) {
19        if (dfs(root) == 0)
20            cameras++;
21        return cameras;
22    }
23};