// Last updated: 7/18/2026, 2:03:54 PM

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL)
                    q.push(node->right);
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};