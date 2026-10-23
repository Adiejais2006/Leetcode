// Last updated: 10/23/2026, 12:43:57 PM
1class Solution {
2    bool isleaf(TreeNode* root) {
3        if (root->left == NULL && root->right == NULL)
4            return true;
5        return false;
6    }
7    void func(TreeNode* root, int& sum, int currentdepth, int &maxdepth) {
8        if (root == NULL)
9            return;
10        if (isleaf(root)) {
11            if (currentdepth > maxdepth) {
12                maxdepth = currentdepth;
13                sum = root->val;
14            } else if (currentdepth == maxdepth)
15                sum += root->val;
16            return; 
17        }
18        func(root->left, sum, currentdepth + 1, maxdepth);
19        func(root->right, sum, currentdepth + 1, maxdepth);
20    }
21
22public:
23    int deepestLeavesSum(TreeNode* root) {
24        int sum = 0;
25        int maxdepth = 0;
26        func(root, sum, 0, maxdepth);
27        return sum;
28    }
29};