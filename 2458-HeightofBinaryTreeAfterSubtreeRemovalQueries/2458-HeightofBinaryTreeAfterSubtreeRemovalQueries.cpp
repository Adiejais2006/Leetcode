// Last updated: 9/11/2026, 1:31:15 PM
1class Solution {
2    int func(TreeNode* root, unordered_map<int, int>& height) {
3        if (!root)
4            return -1;
5
6        return height[root->val] =
7            1 + max(func(root->left, height),
8                    func(root->right, height));
9    }
10    void dfs(TreeNode* root, int depth, int outsideHeight,
11             unordered_map<int, int>& height,
12             unordered_map<int, int>& ans) {
13        if (!root)
14            return;
15        ans[root->val] = outsideHeight;
16        if (root->left) {
17            int siblingHeight = -1;
18            if (root->right)
19                siblingHeight = height[root->right->val];
20            int newOutside =
21                max(outsideHeight,
22                    depth + 1 + siblingHeight);
23            dfs(root->left, depth + 1,
24                newOutside, height, ans);
25        }
26        if (root->right) {
27            int siblingHeight = -1;
28            if (root->left)
29                siblingHeight = height[root->left->val];
30            int newOutside =
31                max(outsideHeight,
32                    depth + 1 + siblingHeight);
33            dfs(root->right, depth + 1,
34                newOutside, height, ans);
35        }
36    }
37public:
38    vector<int> treeQueries(TreeNode* root,
39                            vector<int>& queries) {
40        unordered_map<int, int> height;
41        func(root, height);
42        unordered_map<int, int> ans;
43        dfs(root, 0, 0, height, ans);
44        vector<int> result;
45        for (int query : queries)
46            result.push_back(ans[query]);
47        return result;
48    }
49};