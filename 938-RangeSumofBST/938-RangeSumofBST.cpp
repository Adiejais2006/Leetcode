// Last updated: 10/24/2026, 4:01:44 PM
1class Solution {
2    void func(TreeNode* root, int& sum, int low, int high) {
3        if (root == nullptr)
4            return;
5        if (root->val >= low && root->val <= high) {
6            sum += root->val;
7            func(root->left, sum, low, high);
8            func(root->right, sum, low, high);
9        }
10
11        if (root->val < low) {
12            func(root->right, sum, low, high);
13
14        } else if (root->val > high)
15            func(root->left, sum, low, high);
16    }
17
18public:
19    int rangeSumBST(TreeNode* root, int low, int high) {
20        int sum = 0;
21        func(root, sum, low, high);
22        return sum;
23    }
24};