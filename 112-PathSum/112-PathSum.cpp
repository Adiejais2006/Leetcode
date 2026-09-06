// Last updated: 9/6/2026, 4:12:54 PM
1class Solution {
2    bool isLeaf(TreeNode* root) {
3        if (root->left == NULL && root->right == NULL)
4            return true;
5        return false;
6    }
7    bool func(TreeNode* root, int sum, int target) {
8        if (root == NULL)
9            return false;
10        sum += root->val;
11        if (isLeaf(root)) {
12            if (sum == target)
13                return true;
14            return false;
15        }
16        bool left = func(root->left, sum, target);
17        bool right = func(root->right, sum, target);
18        return left || right;
19    }
20
21public:
22    bool hasPathSum(TreeNode* root, int targetSum) {
23        return func(root, 0, targetSum);
24    }
25};