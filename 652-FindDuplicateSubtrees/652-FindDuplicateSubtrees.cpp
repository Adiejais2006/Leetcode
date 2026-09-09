// Last updated: 9/9/2026, 4:32:48 PM
1class Solution {
2    string func(TreeNode* root, vector<TreeNode*>& ans,
3                unordered_map<string, int>& mpp) {
4
5        if (root == NULL)
6            return "#";
7
8        string left = func(root->left, ans, mpp);
9        string right = func(root->right, ans, mpp);
10
11        string a = to_string(root->val) + "," + left + "," + right;
12
13        mpp[a]++;
14
15        if (mpp[a] == 2)
16            ans.push_back(root);
17
18        return a;
19    }
20
21public:
22    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
23        unordered_map<string, int> mpp;
24        vector<TreeNode*> ans;
25
26        func(root, ans, mpp);
27
28        return ans;
29    }
30};