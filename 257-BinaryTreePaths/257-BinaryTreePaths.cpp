// Last updated: 7/18/2026, 2:05:09 PM
class Solution {
    void func(TreeNode* node, vector<string>& ans, string path) {
        if (node == NULL) return;

       
        if (!path.empty()) path += "->";
        path += to_string(node->val);

        
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(path);
            return;
        }

       
        func(node->left, ans, path);
        func(node->right, ans, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        func(root, ans, "");
        return ans;
    }
};