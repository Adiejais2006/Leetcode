// Last updated: 9/7/2026, 4:19:26 PM
1class Solution {
2    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd,
3                    vector<int>& preorder, vector<int>& inorder,
4                    unordered_map<int, int>& mpp) {
5        if (preStart > preEnd)
6            return NULL;
7        TreeNode* root = new TreeNode(preorder[preStart]);
8        int inRoot = mpp[root->val];
9        int numsLeft = inRoot - inStart;
10        root->left = build(preStart + 1, preStart + numsLeft, inStart, inStart + numsLeft,
11                           preorder, inorder, mpp);
12        root->right = build(preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd,
13                            preorder, inorder, mpp);
14        return root;
15    }
16
17public:
18    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
19        unordered_map<int, int> mpp;
20        for (int i = 0; i < inorder.size(); i++) {
21            mpp[inorder[i]] = i;
22        }
23        TreeNode* root = build(0, preorder.size() - 1, 0, inorder.size() - 1,
24                               preorder, inorder, mpp);
25        return root;
26    }
27};