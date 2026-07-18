// Last updated: 7/18/2026, 2:02:54 PM

class Solution {

bool transverse(TreeNode* root , int val){
    if(root==NULL) return true;
    if(root->val!=val) return false;
    return transverse(root->left,val) && transverse ( root->right,val);
}
public:
    bool isUnivalTree(TreeNode* root) {
        int value =  root->val;
        return transverse(root , value);
    }
};