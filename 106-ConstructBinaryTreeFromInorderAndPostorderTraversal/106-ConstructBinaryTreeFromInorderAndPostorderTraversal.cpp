// Last updated: 7/18/2026, 2:06:31 PM

class Solution { TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int posStart, int posEnd,
                    unordered_map<int, int>& mpp) {
        if (posStart > posEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[posEnd]);
        int inRoot = mpp[root->val] ;
        int numsLeft = inRoot - inStart;
        root->left = build(inorder, inStart, inRoot - 1, postorder, posStart,
                           posStart + numsLeft - 1, mpp);
        root->right = build(inorder, inRoot + 1, inEnd, postorder,
                            posStart + numsLeft, posEnd - 1, mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        };
        TreeNode* root = build(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, mpp);
        return root;
    }
};