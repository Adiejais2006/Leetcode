// Last updated: 7/18/2026, 2:03:51 PM
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
class Solution {class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;   

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse) node = node->right;
            else node = node->left;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (reverse) pushAll(temp->left);
        else pushAll(temp->right);

        return temp->val;
    }
};

public:
    bool findTarget(TreeNode* root, int k) {
          if (!root) return false;

        BSTIterator l(root, false); // smallest
        BSTIterator r(root, true);  // largest

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }

        return false; 
    }
};