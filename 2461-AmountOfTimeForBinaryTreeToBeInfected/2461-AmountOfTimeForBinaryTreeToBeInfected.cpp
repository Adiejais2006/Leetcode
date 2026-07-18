// Last updated: 7/18/2026, 2:00:42 PM
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
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
          int ans = 0;
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> parents;
        // parents mapping
        TreeNode* target = NULL;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == start) {
                target = node;
            }
            if (node->left != NULL) {
                parents[node->left] = node;
                q.push(node->left);
            }
            if (node->right != NULL) {
                parents[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*, bool> vis;  // node aur true or fale
        // node aur cureebt timne
        queue<pair<TreeNode*, int>> Q;
        Q.push({target, 0});
        while (!Q.empty()) {
            TreeNode* node = Q.front().first;
            int time = Q.front().second;
            Q.pop();
            ans = max(ans, time);
            vis[node] = true;
            if (node->left != NULL && vis.find(node->left) == vis.end()) {
                Q.push({node->left, time + 1});
            }
            if (node->right != NULL && vis.find(node->right) == vis.end()) {
                Q.push({node->right, time + 1});
            }
            if (parents[node] != NULL && vis.find(parents[node]) == vis.end()) {
                Q.push({parents[node], time + 1});
            }
        }
        return ans;
    }
};