// Last updated: 7/18/2026, 2:05:47 PM

class BSTIterator {
    stack<TreeNode*> st;
    TreeNode* node;
    void left(TreeNode* root, stack<TreeNode*>& st) {
        if (root == NULL)
            return;
        st.push(root);
        left(root->left, st);
    }

public:
    BSTIterator(TreeNode* root) {
        node = root;
        left(node, st);
    }

    int next() {
        TreeNode* nodee = st.top();
        st.pop();
        int ele = nodee->val;

        if (nodee->right != NULL)
            left(nodee->right, st);
        return ele;
    }

    bool hasNext() { return !st.empty(); }
};
