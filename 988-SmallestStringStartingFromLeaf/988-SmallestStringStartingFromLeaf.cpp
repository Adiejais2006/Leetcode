// Last updated: 10/23/2026, 7:12:13 PM
1class Solution {
2    string ans = "";
3    bool isleaf(TreeNode* root) {
4        if (root->left == nullptr && root->right == nullptr)
5            return true;
6        return false;
7    }
8    void func(TreeNode* root, string &temp) {
9        if (root == nullptr)
10            return;
11        temp += 'a' + root->val;
12        if (isleaf(root)) {
13            string revtemp = temp;
14            reverse(revtemp.begin(), revtemp.end());
15            if (ans=="" || revtemp < ans) {
16                ans = revtemp;
17            }
18        }
19        func(root->left, temp);
20        func(root->right, temp);
21        temp.pop_back();
22    }   
23
24public:
25    string smallestFromLeaf(TreeNode* root) {
26        string temp = "";
27        func(root, temp);
28        return ans;
29    }
30};