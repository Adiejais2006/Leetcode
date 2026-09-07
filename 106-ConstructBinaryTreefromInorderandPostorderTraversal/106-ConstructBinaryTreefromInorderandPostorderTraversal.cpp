// Last updated: 9/7/2026, 5:08:11 PM
1class Solution {
2    TreeNode* build(int inStart, int inEnd, int postStart, int postEnd,
3                    vector<int>& inorder, vector<int>& postorder,
4                    unordered_map<int, int>& mpp) {
5        if (inStart > inEnd || postStart > postEnd)
6            return NULL;
7        TreeNode* root = new TreeNode (postorder[postEnd]);
8        int inRoot = mpp[root->val];
9        int numLeft = inRoot - inStart;
10        root->left = build(inStart, inRoot - 1, postStart,
11                           postStart + numLeft - 1, inorder, postorder, mpp);
12        root->right = build(inRoot + 1, inEnd, postStart + numLeft ,
13                            postEnd-1, inorder, postorder, mpp);
14        return root;
15    }
16
17public:
18    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
19        unordered_map<int, int> mpp;
20        for (int i =0 ; i < inorder.size(); i++) {
21            mpp[inorder[i]] = i;
22        }
23
24        TreeNode* root = build(0 , inorder.size()-1 , 0 , postorder.size()-1,inorder,postorder,mpp);
25        return root;
26    }
27};