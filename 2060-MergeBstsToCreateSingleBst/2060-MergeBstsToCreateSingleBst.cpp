// Last updated: 7/18/2026, 2:01:18 PM
class Solution {
public:
    unordered_map<int, TreeNode*> roots;
    unordered_set<int> leaves;
    unordered_set<int> used;

    bool validate(TreeNode* node, long long mn, long long mx) {
        if (!node) return true;

        if (node->val <= mn || node->val >= mx) return false;

        if (!node->left && !node->right && roots.count(node->val) && !used.count(node->val)) {
            used.insert(node->val);
            TreeNode* t = roots[node->val];
            node->left = t->left;
            node->right = t->right;
        }

        return validate(node->left, mn, node->val) &&
               validate(node->right, node->val, mx);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (auto t : trees) {
            roots[t->val] = t;

            if (t->left) leaves.insert(t->left->val);
            if (t->right) leaves.insert(t->right->val);
        }

        TreeNode* root = nullptr;

        for (auto t : trees) {
            if (!leaves.count(t->val)) {
                root = t;
                break;
            }
        }

        if (!root) return nullptr;

        used.insert(root->val);

        if (!validate(root, LLONG_MIN, LLONG_MAX)) return nullptr;

        if (used.size() != trees.size()) return nullptr;

        return root;
    }
};