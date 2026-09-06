// Last updated: 9/6/2026, 6:33:30 PM
1
2class Solution {
3public:
4    vector<int> rightSideView(TreeNode* root) {
5        if (root == nullptr)
6            return {};
7        queue<TreeNode*> q;
8        q.push(root);
9        vector<int> ans;
10        while (!q.empty()) {
11            auto size = q.size();
12
13            for (int i = 0; i < size; i++) {
14                auto a = q.front();
15                q.pop();
16                if (i == size - 1)
17                    ans.push_back(a->val);
18                if (a->left != NULL)
19                    q.push(a->left);
20                if (a->right != NULL)
21                    q.push(a->right);
22            }
23        }
24        return ans;
25    }
26};