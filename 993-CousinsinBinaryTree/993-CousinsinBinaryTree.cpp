// Last updated: 9/11/2026, 3:02:01 PM
1class Solution {
2public:int xdepth, ydepth, xparent, yparent;
3void depth(TreeNode* root, int x, int y, int dep, int par_val){
4    if(root==NULL) return;
5    if(root->val==x){
6        xdepth=dep;
7        xparent=par_val;
8        return;
9    }
10    if(root->val==y){
11        ydepth=dep;
12        yparent=par_val;
13        return;
14    }
15    depth(root->left, x, y, dep+1, root->val);
16    depth(root->right, x, y, dep+1, root->val);
17}
18bool isCousins(TreeNode* root, int x, int y) {
19    if(root->val==x || root->val==y) return false;
20    depth(root, x, y, 0, 0);
21    if(xdepth==ydepth && xparent!=yparent) return true;
22    return false;
23}
24};