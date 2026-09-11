// Last updated: 9/11/2026, 3:30:06 PM
1class Solution {
2public:
3    TreeNode* replaceValueInTree(TreeNode* root) {
4        root->val = 0;
5        queue<TreeNode*> q;
6        q.push(root);
7        while (!q.empty()) {
8            int n = q.size();
9            int sum = 0;
10            vector<TreeNode*> a;
11            while (n--) {
12                auto node = q.front();
13                q.pop();
14                a.push_back(node);
15                if (node->left) {
16                    q.push(node->left);
17                    sum += node->left->val;
18                }
19                if (node->right) {
20                    q.push(node->right);
21                    sum += node->right->val;
22                }
23            }
24            for (auto it : a) {
25                int summ = sum;
26                if (it->left) {
27                    summ -= it->left->val;
28                }
29                if (it->right) {
30                    summ -= it->right->val;
31                }
32                if (it->left)
33                    it->left->val = summ;
34                if (it->right)
35                    it->right->val = summ;
36            }
37        }
38        return root;
39    }
40};