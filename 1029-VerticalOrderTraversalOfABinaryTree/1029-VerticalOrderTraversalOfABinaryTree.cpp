// Last updated: 7/18/2026, 2:02:47 PM
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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<pair<TreeNode*, pair<int, int>>> q;  // for maintaing the order
        q.push({root, {0, 0}});
        // x coordinate main sorting then comes y coordinate and its total nodes
        // in a sorted fashion
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mpp;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            mpp[x][y].push(node->val);
            q.pop();
            if (node->left != NULL) {
                TreeNode* tempNode = node->left;
                int xCor = x - 1;
                int yCor = y + 1;
                q.push({tempNode, {xCor, yCor}});
            }
            if (node->right != NULL) {
                TreeNode* tempNode = node->right;
                int xCor = x + 1;
                int yCor = y + 1;
                q.push({tempNode, {xCor, yCor}});
            };
        }
        //   map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>
        //   mpp;
        for (auto it : mpp) {
            // getting all the values for the x and y copordinate  mpp[x][y]
            vector<int> a;
            for (auto i : it.second) {
                priority_queue<int , vector<int> , greater<int>> temp;
                temp = i.second;
                while (!temp.empty()) {
                    a.push_back(temp.top());
                    temp.pop();
                }
            }
            ans.push_back(a);
        }

        return ans;
    }
};