// Last updated: 9/6/2026, 2:30:28 PM
1class Solution {
2    int depth(TreeNode* root){
3        if(root==NULL) return 0 ;
4        int left = 1 + depth(root->left);
5        int right = 1 + depth(root->right);
6        return max(left,right);
7    }
8public:
9    int maxDepth(TreeNode* root) {
10        return depth(root);
11    }
12};