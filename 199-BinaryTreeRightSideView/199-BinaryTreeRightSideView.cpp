// Last updated: 7/18/2026, 2:05:42 PM

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         if(root==NULL) return{};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;  // node aur y coordinate
        map<int, int> mpp;              // y coordinate aur value
        q.push({root, 0});
        while (!q.empty()) {
            auto element = q.front();q.pop();
            TreeNode* node = element.first;
            int y = element.second;
            int val = node->val;
            mpp[y] = val;
            if (node->left != NULL) {
                q.push({node->left, y + 1});
            }
            if (node->right != NULL) {
                q.push({node->right, y + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};