// Last updated: 7/18/2026, 2:03:28 PM

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        while(root!=NULL){
            if(root->val==val) return root;
            else if (root->val>val) root=root->left;
            else root = root->right;
        }
        return root;
    }
};