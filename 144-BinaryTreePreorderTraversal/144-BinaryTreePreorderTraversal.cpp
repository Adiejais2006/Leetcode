// Last updated: 7/18/2026, 2:06:00 PM

class Solution {  void preorder(vector<int>& arr, TreeNode* root) {
        if (root == NULL) return;
        arr.push_back(root->val);
        preorder(arr,  root->left);
        preorder(arr, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
        preorder(ans, root);
        return ans;
    }
};