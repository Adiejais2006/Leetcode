// Last updated: 7/18/2026, 2:00:34 PM
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(root, v);

        vector<vector<int>> ans;

        for (int q : queries) {
            auto it = lower_bound(v.begin(), v.end(), q);

            int mn = -1, mx = -1;

            if (it != v.end() && *it == q) {
                mn = mx = q;
            } else {
                if (it != v.begin()) mn = *(prev(it));
                if (it != v.end()) mx = *it;
            }

            ans.push_back({mn, mx});
        }

        return ans;
    }
};