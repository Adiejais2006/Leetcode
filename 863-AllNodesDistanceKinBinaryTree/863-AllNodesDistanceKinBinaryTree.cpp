// Last updated: 9/7/2026, 11:17:44 PM
1
2class Solution {
3    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp) {
4        if (root == NULL)
5            return;
6        if (root->left != NULL) {
7            mpp[root->left] = root;
8            parent(root->left, mpp);
9        }
10        if (root->right != NULL) {
11            mpp[root->right] = root;
12            parent(root->right, mpp);
13        }
14    }
15    void func(TreeNode* target, int k, vector<int>& ans,
16              unordered_set<TreeNode*>& visited,
17              unordered_map<TreeNode*, TreeNode*>& mpp) {
18        if (target == NULL || visited.count(target))
19            return;
20        if (k == 0) {
21            ans.push_back(target->val);
22            return;
23        }
24        visited.insert(target);
25        func(target->left, k-1, ans, visited, mpp);
26        func(target->right, k-1, ans, visited, mpp);
27        func(mpp[target], k-1, ans, visited, mpp);
28    }
29
30public:
31    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
32        vector<int> ans;
33        unordered_map<TreeNode*, TreeNode*> mpp;
34        unordered_set<TreeNode*> visited;
35        parent(root, mpp);
36        func(target, k, ans, visited, mpp);
37        return ans;
38    }
39};