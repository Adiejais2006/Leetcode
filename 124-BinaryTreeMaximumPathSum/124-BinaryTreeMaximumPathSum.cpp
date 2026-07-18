// Last updated: 7/18/2026, 2:06:16 PM
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
class Solution { int func(int& ans, TreeNode* root) {
        if (root == NULL) return 0;
        int left = max(0 , func(ans, root->left)); // negative paths nodes ko ignore kr rhe hI
        int right = max(0,func(ans, root->right));
        ans = max(ans,left + right + root->val); // isse left aur right ki depth merge hoke ek ban jayegi 
        return root->val + max(left, right); // ye depth nikalke dega 
    }
public:
    int maxPathSum(TreeNode* root) {
          int ans = INT_MIN;

        func(ans, root);

        return ans;
    }
};