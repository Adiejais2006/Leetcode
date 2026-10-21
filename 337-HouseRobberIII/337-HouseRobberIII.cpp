// Last updated: 10/21/2026, 10:25:57 PM
1class Solution {
2    int func(TreeNode* root,unordered_map<TreeNode*,int> &mpp) {
3        if (root == nullptr)
4            return  0;
5        if(mpp.find(root)!=mpp.end()) return mpp[root];
6        int nottake = func(root->left ,mpp) + func(root->right ,mpp);
7        int take = root->val + (root->left ? func(root->left->left ,mpp) : 0) +
8                   (root->left ? func(root->left->right ,mpp) : 0) +
9                   (root->right ? func(root->right->left ,mpp) : 0) +
10                   (root->right ? func(root->right->right ,mpp) : 0);
11        return mpp[root] =  max(take, nottake);
12    }
13
14public:
15    int rob(TreeNode* root) { 
16        unordered_map<TreeNode*,int> mpp;
17        return func(root ,mpp); }
18};