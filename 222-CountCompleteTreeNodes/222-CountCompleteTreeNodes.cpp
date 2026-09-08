// Last updated: 9/8/2026, 6:51:12 PM
1class Solution {
2    int leftheight(TreeNode* root) {
3        if (root == NULL)
4            return 0;
5        return 1 + leftheight(root->left);
6    }
7    int rightheight(TreeNode* root) {
8        if (root == NULL)
9            return 0;
10        return 1 + rightheight(root->right);
11    }
12    int nodes(TreeNode* root) {
13        if (root == NULL)
14            return 0;
15
16        int lh = leftheight(root);
17        int rh = rightheight(root);
18        if (lh == rh) {
19            return (1 << lh) - 1;
20        }
21        return 1 + nodes(root->left) + nodes(root->right);
22    }
23
24public:
25    int countNodes(TreeNode* root) { return nodes(root); }
26};