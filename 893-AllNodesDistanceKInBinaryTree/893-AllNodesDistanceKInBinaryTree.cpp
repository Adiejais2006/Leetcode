// Last updated: 7/18/2026, 2:03:09 PM

class Solution {
    void build(TreeNode* root,
               unordered_map<TreeNode*, vector<TreeNode*>>& mpp) {
        if (root == NULL)
            return;
        if (root->left) {
            mpp[root].push_back(root->left);
            mpp[root->left].push_back(root);
            build(root->left, mpp);
        }
        if (root->right) {
            mpp[root].push_back(root->right);
            mpp[root->right].push_back(root);
            build(root->right, mpp);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> mpp;
        build(root, mpp);
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            auto node = a.first;
            auto dist = a.second;
            vis.insert(node);
            if (dist > k)
                continue;
            if (dist == k)
                ans.push_back(node->val);

           for (auto it : mpp[node]) {
    if (!vis.count(it)) {
        vis.insert(it);
        q.push({it, dist + 1});
    }
}
        }
        return ans;
    }
};