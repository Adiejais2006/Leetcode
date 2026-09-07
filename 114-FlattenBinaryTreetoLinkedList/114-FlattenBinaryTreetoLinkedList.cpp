// Last updated: 9/7/2026, 6:21:03 PM
1class Solution {
2    void change(TreeNode* root, TreeNode* &prev){
3        if(root==NULL)return;
4        change(root->right , prev);
5        change(root->left , prev);
6        root->right = prev;
7        root->left = NULL;
8        prev = root;
9        
10    }
11public:
12    void flatten(TreeNode* root) {
13        TreeNode* prev = NULL;
14        change(root,prev);
15    }
16};