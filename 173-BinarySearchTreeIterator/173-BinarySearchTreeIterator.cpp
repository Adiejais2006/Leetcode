// Last updated: 9/8/2026, 6:42:16 PM
1
2class BSTIterator {
3    stack<TreeNode*> st;
4    void left(TreeNode* root, stack<TreeNode*>& st) {
5        if (root == NULL)
6            return;
7        st.push(root);
8        left(root->left, st);
9    }
10
11public:
12    BSTIterator(TreeNode* root) {
13        stack<TreeNode*> a;
14        left(root, a);
15        st = a;
16    }
17
18    int next() {
19        auto node = st.top();
20        st.pop();
21        if (node->right)
22            left(node->right, st);
23        return node->val;
24    }
25
26    bool hasNext() { return !st.empty(); }
27};
28