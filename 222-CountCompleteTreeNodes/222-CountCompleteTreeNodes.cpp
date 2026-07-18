// Last updated: 7/18/2026, 2:05:24 PM

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
         long long  ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            long long count = q.front().second;
            q.pop();
            ans = max(ans, count);
            if (node->left != NULL) {
                q.push({node->left, 2*count+1});
            }
            if (node->right != NULL) {
                q.push({node->right, 2*count+2});
            }
        }
        return (int)ans+1;
    }
};