// Last updated: 9/7/2026, 6:33:49 PM
1
2class Solution {
3public:
4    void flatten(TreeNode* root) {
5        if (!root)
6            return;
7        stack<TreeNode*> st;
8        st.push(root);
9        while (!st.empty()) {
10            auto node = st.top();
11            st.pop();
12            if (node->right != NULL)
13                st.push(node->right);
14            if (node->left != NULL)
15                st.push(node->left);
16            if (!st.empty())
17                node->right = st.top();
18            else
19                node->right = NULL;
20            node->left = NULL;
21        }
22    }
23};