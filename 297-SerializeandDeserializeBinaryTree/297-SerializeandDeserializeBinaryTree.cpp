// Last updated: 9/7/2026, 7:04:46 PM
1
2class Codec {
3public:
4    void preorder(TreeNode* root, string& ans) {
5        if (root == NULL) {
6            ans += "#,";
7            return;
8        }
9        ans += to_string(root->val) + ",";
10        preorder(root->left, ans);
11        preorder(root->right, ans);
12    }
13    string serialize(TreeNode* root) {
14        string ans = "";
15        preorder(root, ans);
16        return ans;
17    }
18
19    TreeNode* build(stringstream& ss) {
20        string value;
21        getline(ss, value, ',');
22        if(value=="#")return NULL;
23        TreeNode* root = new TreeNode(stoi(value));
24        root->left = build(ss);
25        root->right = build(ss);
26        return root;
27    }
28
29    TreeNode* deserialize(string data) {
30        if (data == "")
31            return NULL;
32        stringstream ss(data);
33        return build(ss);
34    }
35};
36