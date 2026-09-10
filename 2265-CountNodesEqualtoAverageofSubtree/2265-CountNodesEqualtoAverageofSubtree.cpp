// Last updated: 9/10/2026, 9:34:47 PM
1
2class Solution {
3
4    pair<int, int> avg(TreeNode* node, int& cnt) {
5        if (!node)
6            return {0, 0};
7        auto left = avg(node->left, cnt);
8        auto right = avg(node->right, cnt);
9        int currentSum = left.first + right.first + node->val;
10        int currentCount = left.second + right.second + 1;
11        if (currentSum / currentCount == node->val) {
12            cnt++;
13        }
14
15        return {currentSum, currentCount};
16    }
17
18public:
19    int averageOfSubtree(TreeNode* root) {
20        int cnt = 0;
21        avg(root, cnt);
22        return cnt;
23    }
24};