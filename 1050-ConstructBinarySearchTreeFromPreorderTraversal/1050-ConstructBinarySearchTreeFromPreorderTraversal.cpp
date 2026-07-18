// Last updated: 7/18/2026, 2:02:41 PM

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         if (preorder.empty()) return nullptr;
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = st.top();
            TreeNode* child = new TreeNode(preorder[i]);
            while (!st.empty() && st.top()->val < preorder[i]) {
                node = st.top();
                st.pop();
            }
            if (node->val > preorder[i]) {
                node->left = child;
            } else {
                node->right = child;
            }
            st.push(child);
        }
        return root;
    }
};