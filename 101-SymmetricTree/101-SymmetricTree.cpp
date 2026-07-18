// Last updated: 7/18/2026, 2:06:37 PM

class Solution {  bool func(TreeNode* leftP, TreeNode* rightP) {
       if(leftP==NULL || rightP==NULL) return leftP==rightP;
        if (leftP->val != rightP->val)
            return false;
        bool left = func(leftP->left, rightP->right);
        bool right = func(leftP->right, rightP->left);
        return left && right;
    }
public:
    bool isSymmetric(TreeNode* root) {
          if (!root) return true;
        return func(root->left, root->right);
    }
};