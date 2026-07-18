// Last updated: 7/18/2026, 2:04:17 PM

class Solution {
    void inorder(TreeNode* root, unordered_map<int, int>& mpp) {
        if (root == NULL)
            return;
        inorder(root->left, mpp);
        mpp[root->val]++;
        inorder(root->right, mpp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mpp;
        inorder(root, mpp);
        int ans = 0;
        for (auto it : mpp) {
            ans = max(ans, it.second);
        }

        vector<int> a;

        for (auto it : mpp) {
            if (ans == it.second) {
                a.push_back(it.first);
            }
        }
        return a;
    }
};