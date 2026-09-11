// Last updated: 9/11/2026, 1:58:45 PM
1class Solution {
2    struct Node {
3        bool isBST;
4        long long sum;
5        int mini;
6        int maxi;
7    };
8    long long ans = 0;
9    Node func(TreeNode* root) {
10        if (!root) {
11            return {true, 0, INT_MAX, INT_MIN};
12        }
13        Node left = func(root->left);
14        Node right = func(root->right);
15        if (left.isBST && right.isBST && left.maxi < root->val &&
16            root->val < right.mini) {
17            long long sum = left.sum + right.sum + root->val;
18            ans = max(ans, sum);
19            return {true, sum, min(root->val, left.mini),
20                    max(root->val, right.maxi)};
21        }
22        return {false, 0, 0, 0};
23    }
24
25public:
26    int maxSumBST(TreeNode* root) {
27        func(root);
28        return (int)ans;
29    }
30};