// Last updated: 9/6/2026, 4:15:37 PM
1class Solution {
2    bool isLeaf(TreeNode* root) {
3        if (root->left == NULL && root->right == NULL)
4            return true;
5        return false;
6    }
7    bool func(TreeNode* root, int target) {
8        if (root == NULL)
9            return false;
10        if (isLeaf(root)) {
11            return target==root->val;
12        }
13        bool left = func(root->left, target - root->val);
14        bool right = func(root->right, target - root->val);
15        return left || right;
16    }
17
18public:
19    bool hasPathSum(TreeNode* root, int targetSum) {
20        return func(root, targetSum);
21    }
22};