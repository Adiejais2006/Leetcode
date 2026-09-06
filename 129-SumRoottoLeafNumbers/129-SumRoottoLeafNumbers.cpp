// Last updated: 9/6/2026, 4:49:27 PM
1
2class Solution {
3    bool isLeaf(TreeNode* root) {
4        if (root->left == NULL && root->right == NULL)
5            return true;
6        return false;
7    }
8
9    void func(TreeNode* root, int& ans, int number) {
10        if (root == NULL)
11            return;
12        number = number * 10 + root->val;
13        if (isLeaf(root)) {
14            ans += number;
15        }
16        func(root->left, ans, number);
17        func(root->right, ans, number);
18    }
19
20public:
21    int sumNumbers(TreeNode* root) {
22        int ans = 0;
23        func(root, ans, 0);
24        return ans;
25    }
26};