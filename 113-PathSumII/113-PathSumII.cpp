// Last updated: 9/6/2026, 4:28:25 PM
1class Solution {
2    bool isLeaf(TreeNode* root) {
3        if (root->left == NULL && root->right == NULL)
4            return true;
5        return false;
6    }
7    void func(TreeNode* root, int target, vector<int>& temp,
8              vector<vector<int>>& ans) {
9        if (root == NULL)
10            return;
11        temp.push_back(root->val);
12        if (isLeaf(root)) {
13            if (target == root->val) {
14                ans.push_back(temp);
15            }
16        }
17        func(root->left, target - root->val, temp, ans);
18        func(root->right, target - root->val, temp, ans);
19        temp.pop_back();
20    }
21
22public:
23    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
24        vector<vector<int>> ans;
25        vector<int> temp;
26        func(root, targetSum, temp, ans);
27        return ans;
28    }
29};