// Last updated: 7/18/2026, 2:06:35 PM
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        queue<TreeNode*> st;
        vector<vector<int>> ans;
        bool lefttoright = true;

        st.push(root);

        while (!st.empty()) {
            int size = st.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* temp = st.front();
                st.pop();

                if (lefttoright)
                    level[i] = temp->val;
                else
                    level[size - i - 1] = temp->val;

                if (temp->left)
                    st.push(temp->left);

                if (temp->right)
                    st.push(temp->right);
            }

            ans.push_back(level);
            lefttoright = !lefttoright;
        }

        return ans;
    }
};