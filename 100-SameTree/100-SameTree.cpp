// Last updated: 9/6/2026, 2:36:13 PM
1
2class Solution {
3    bool func(TreeNode* p, TreeNode* q){
4        if(p==NULL && q==NULL) return true;
5        if(p==NULL || q==NULL || p->val!=q->val) return false;
6        bool a = func(p->left , q->left);
7        bool b = func(p->right , q->right);
8        return a&&b;
9    }
10public:
11    bool isSameTree(TreeNode* p, TreeNode* q) {
12        return func(p,q);
13    }
14};