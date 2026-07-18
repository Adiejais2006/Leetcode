// Last updated: 7/18/2026, 2:06:45 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { void preorder(vector<int>& arr, TreeNode* root) {
        if (root == NULL) return;
        preorder(arr,  root->left);
        arr.push_back(root->val);
        preorder(arr, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        preorder(ans,root);
        return ans ;
    }
};