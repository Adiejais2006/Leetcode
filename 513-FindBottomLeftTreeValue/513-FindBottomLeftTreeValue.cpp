// Last updated: 7/18/2026, 2:04:13 PM
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = root->val;

        while (!q.empty()) {
            int n = q.size();

            ans = q.front()->val; // current level ka leftmost

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};