// Last updated: 7/18/2026, 2:05:59 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   void postOrder(vector<int>&arr ,TreeNode* root){
      if (root == NULL) return;
    postOrder(arr, root->left);
    postOrder(arr, root->right);
    arr.push_back(root->val);
}

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(ans, root);
        return ans;
    }
};