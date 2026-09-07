// Last updated: 9/8/2026, 12:12:09 AM
1
2class Solution {
3    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp,
4                int start, TreeNode*& startNode) {
5        if (root == NULL)
6            return;
7        if (root->val == start)
8            startNode = root;
9        if (root->left != NULL) {
10            mpp[root->left] = root;
11            parent(root->left, mpp, start, startNode);
12        }
13        if (root->right != NULL) {
14            mpp[root->right] = root;
15            parent(root->right, mpp, start, startNode);
16        }
17    }
18
19    void bfs(int& time, TreeNode* root,
20             unordered_map<TreeNode*, TreeNode*>& parent,
21             unordered_set<TreeNode*>& vis) {
22        queue<pair<TreeNode*, int>> q;
23        q.push({root, time});
24        vis.insert(root);
25        while (!q.empty()) {
26            auto it = q.front();
27            q.pop();
28            auto node = it.first;
29            int currTime = it.second;
30            time = max(time , currTime);
31            currTime++;
32            if (node->left != NULL && !vis.count(node->left)) {
33                q.push({node->left, currTime});
34                vis.insert(node->left);
35            }
36            if (node->right && !vis.count(node->right)) {
37                q.push({node->right, currTime});
38                vis.insert(node->right);
39            }
40            if (parent[node] != NULL && !vis.count(parent[node])) {
41                q.push({parent[node], currTime});
42                vis.insert(parent[node]);
43            }
44        }
45    }
46
47public:
48    int amountOfTime(TreeNode* root, int start) {
49        unordered_map<TreeNode*, TreeNode*> mpp;
50        unordered_set<TreeNode*> vis;
51        TreeNode* startnode;
52        parent(root, mpp, start, startnode);
53        int time = 0;
54        bfs(time, startnode, mpp, vis);
55        return time;
56    }
57};