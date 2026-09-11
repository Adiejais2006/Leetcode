// Last updated: 9/11/2026, 3:59:55 PM
1class Solution {
2    TreeNode* lca(TreeNode* root, int p, int q) {
3        if (!root)
4            return nullptr;
5        if (root->val == p || root->val == q)
6            return root;
7        TreeNode* left = lca(root->left, p, q);
8        TreeNode* right = lca(root->right, p, q);
9        if (!left)
10            return right;
11        if (!right)
12            return left;
13        return root;
14    }
15    bool findPath(TreeNode* root, int x, string& path) {
16        if (!root)
17            return false;
18        if (root->val == x)
19            return true;
20        path.push_back('L');
21        if (findPath(root->left, x, path))
22            return true;
23        path.pop_back();
24        path.push_back('R');
25        if (findPath(root->right, x, path))
26            return true;
27        path.pop_back();
28        return false;
29    }
30
31public:
32    string getDirections(TreeNode* root, int startValue, int destValue) {
33        TreeNode* common = lca(root, startValue, destValue);
34        string startPath;
35        string destPath;
36        findPath(common, startValue, startPath);
37        findPath(common, destValue, destPath);
38        string ans(startPath.size(), 'U');
39        ans += destPath;
40        return ans;
41    }
42};