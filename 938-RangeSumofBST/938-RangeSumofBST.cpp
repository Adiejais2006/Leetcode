// Last updated: 10/24/2026, 3:58:46 PM
1class Solution {
2    void func(TreeNode* root, int& sum, int low, int high) {
3        if (root == nullptr)
4            return;
5        if (root->val >= low && root->val <= high)
6            sum += root->val;
7        func(root->left, sum, low, high);
8        func(root->right, sum, low, high);
9    }
10
11public:
12    int rangeSumBST(TreeNode* root, int low, int high) {
13        int sum = 0;
14        func(root, sum, low, high);
15        return sum;
16    }
17};