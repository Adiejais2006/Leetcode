// Last updated: 7/18/2026, 2:06:27 PM
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    int minDepth(TreeNode* root) {

        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (isLeaf(node))
                    return depth;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            depth++;
        }

        return depth;
    }
};