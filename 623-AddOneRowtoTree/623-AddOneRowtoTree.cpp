// Last updated: 10/23/2026, 1:09:39 PM
1class Solution {
2public:
3    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
4        if(depth==1){
5            TreeNode* newroot = new TreeNode(val);
6            newroot->left = root;
7            return newroot;
8        }
9        int cnt = 1;
10        queue<TreeNode*> q;
11        q.push(root);
12        while (!q.empty() && cnt < depth - 1) {
13            int size = q.size();
14            for (int i = 0; i < size; i++) {
15                auto node = q.front();
16                q.pop();
17                if (node->left) {
18                    q.push(node->left);
19                }
20                if (node->right)
21                    q.push(node->right);
22            }
23            cnt++;
24        }
25
26        while (!q.empty()) {
27            TreeNode* node = q.front();
28            q.pop();
29            TreeNode* nodeleft = NULL;
30            TreeNode* noderight = NULL;
31            TreeNode* one1 = new TreeNode(val);
32            TreeNode* one2 = new TreeNode(val);
33            if (node->left)
34                nodeleft = node->left;
35            if (node->right)
36                noderight = node->right;
37            node->left = one1;
38            node->right = one2;
39            one1->left = nodeleft;
40            one2->right = noderight;
41        }
42        return root;
43    }
44};