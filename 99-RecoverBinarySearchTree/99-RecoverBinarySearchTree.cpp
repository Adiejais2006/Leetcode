// Last updated: 9/13/2026, 4:37:30 PM
1
2
3class Solution {
4    void inorder(vector<int>& arr, TreeNode* root) {
5        if (root == NULL)
6            return;
7        inorder(arr, root->left);
8        arr.push_back(root->val);
9        inorder(arr, root->right);
10    }
11
12    void reqrite(vector<int>& arr, TreeNode* root, int& i) {
13        if (root == NULL)
14            return;
15        reqrite(arr, root->left, i);
16        root->val = arr[i++];
17        reqrite(arr, root->right, i);
18    }
19
20public:
21    void recoverTree(TreeNode* root) {
22        vector<int> arr;
23        inorder(arr, root);
24        sort(arr.begin(), arr.end());
25        int i = 0;
26        reqrite(arr, root, i);
27    }
28};