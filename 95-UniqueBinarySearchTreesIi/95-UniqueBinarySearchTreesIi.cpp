// Last updated: 7/18/2026, 2:06:43 PM
class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            return {NULL};
        }
        if(start==end) return {new TreeNode(start)};
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};  
        return build(1, n);
    }
};