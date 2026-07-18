// Last updated: 7/18/2026, 2:06:38 PM
class Solution {
   private:
    TreeNode* first, *prev, *middle, *last;

   private:
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder( root->left);
        if (prev != NULL && (prev->val > root->val)) {
            if (first == NULL) {
                first = prev;
               middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

   public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
    swap(first->val, last->val);
else if(first && middle)
    swap(first->val, middle->val);

    }
};