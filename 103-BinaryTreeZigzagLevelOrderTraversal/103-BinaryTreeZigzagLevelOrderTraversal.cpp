// Last updated: 9/6/2026, 6:46:27 PM
1
2class Solution {
3public:
4    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
5        if (!root)
6            return {};
7        bool straight = true;
8        vector<vector<int>> ans;
9        queue<TreeNode*> q;
10        q.push(root);
11        while (!q.empty()) {
12            auto size = q.size();
13            vector<int> temp(size);
14            for (int i = 0; i < size; i++) {
15                auto it = q.front();
16                q.pop();
17                if (straight) {
18                    temp[i] = it->val;
19                } else
20                    temp[size - 1 - i] = it->val;
21                if (it->left != NULL)
22                    q.push(it->left);
23                if (it->right != NULL)
24                    q.push(it->right);
25            }
26            straight = !straight;
27            ans.push_back(temp);
28        }
29        return ans;
30    }
31};