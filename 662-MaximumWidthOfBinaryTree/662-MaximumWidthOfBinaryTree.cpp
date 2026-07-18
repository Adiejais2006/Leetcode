// Last updated: 7/18/2026, 2:03:50 PM

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = INT_MIN;
        while (!q.empty()) {
            long long size = q.size();
            long long l;
            long long r;
            long long minus = q.front().second;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long value = q.front().second;
                q.pop();
                if (i == 0) l = value;
                if (i == size - 1) r = value;
                long long left = 2 * value - minus;
                long long right = 2 * value + 1 -minus;
                if (node->left != NULL) q.push({node->left, left});
                if (node->right != NULL) q.push({node->right, right});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;   
    }
};