// Last updated: 9/9/2026, 12:32:05 AM
1class Solution {
2    bool checker(TreeNode* root, TreeNode* subroot) {
3        if (root == NULL && subroot == NULL)
4            return true;
5        if (root == NULL || subroot == NULL || root->val != subroot->val)
6            return false;
7        bool left = checker(root->left, subroot->left);
8        bool right = checker(root->right, subroot->right);
9        return left && right;
10    }
11public:
12    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
13        if (root == NULL)
14            return false;
15        if(checker(root,subRoot)) return true;
16        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
17    }
18};