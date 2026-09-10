// Last updated: 9/11/2026, 1:25:33 AM
1class Solution {
2    int cnt = 0;
3    vector<int> func(TreeNode* root, int dist) {
4        if (root == NULL) {
5            return {};
6        }
7        if (!root->left && !root->right)
8            return {0};
9
10        vector<int> left = func(root->left, dist);
11        vector<int> right = func(root->right, dist);
12        for (auto it : left) {
13            for (auto i : right) {
14                if (it + i + 2 <= dist)
15                    cnt++;
16            }
17        }
18        vector<int> ans;
19        for (auto it : left)
20            ans.push_back(it + 1);
21
22        for (auto it : right)
23            ans.push_back(it + 1);
24
25        return ans;
26    }
27
28public:
29    int countPairs(TreeNode* root, int distance) {
30        func(root, distance);
31        return cnt;
32    }
33};