// Last updated: 9/8/2026, 12:30:26 AM
1
2class Solution {
3public:
4    vector<vector<int>> verticalTraversal(TreeNode* root) {
5        vector<vector<int>> ans;
6        if (root == NULL)
7            return ans;
8        queue<pair<TreeNode*, pair<int, int>>> q;
9        q.push({root, {0, 0}});
10        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mpp;
11        while (!q.empty()) {
12            auto it = q.front();
13            q.pop();
14            auto node = it.first;
15            int x = it.second.first;
16            int y = it.second.second;
17            mpp[x][y].push(node->val);
18            if (node->left) {
19                q.push({node->left, {x - 1, y + 1}});
20            }
21            if (node->right) {
22                q.push({node->right, {x + 1, y + 1}});
23            }
24        }
25        for (auto it : mpp) {
26            vector<int> a;
27            for (auto i : it.second) {
28                priority_queue<int, vector<int>, greater<int>> temp;
29                temp = i.second;
30                while (!temp.empty()) {
31                    a.push_back(temp.top());
32                    temp.pop();
33                }
34            }
35            ans.push_back(a);
36        }
37        return ans;
38    }
39};