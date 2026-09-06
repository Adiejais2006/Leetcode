// Last updated: 9/6/2026, 3:05:31 PM
1
2class Solution {
3public:
4    vector<vector<int>> levelOrder(TreeNode* root) {
5        if (root == NULL)
6            return {};
7        vector<vector<int>> ans;
8        queue<TreeNode*> q;
9        q.push(root);
10        while (!q.empty()) {
11            auto size = q.size();
12            vector<int> temp;
13            while (size--) {
14                auto a = q.front();
15                q.pop();
16                temp.push_back(a->val);
17                if (a->left != NULL)
18                    q.push(a->left);
19                if (a->right != NULL)
20                    q.push(a->right);
21            }
22            ans.push_back(temp);
23        }
24        return ans;
25    }
26};