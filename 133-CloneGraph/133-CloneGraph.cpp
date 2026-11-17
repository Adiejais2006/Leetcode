// Last updated: 11/17/2026, 1:48:32 PM
1
2class Solution {
3    Node* func(Node* node, unordered_map<Node*, Node*>& mpp) {
4        if (node == nullptr)
5            return nullptr;
6        if (mpp.find(node) != mpp.end())
7            return mpp[node];
8        Node* root = new Node(node->val);
9        mpp[node] = root;
10        for (auto it : node->neighbors) {
11            root->neighbors.push_back(func(it, mpp));
12        }
13        return root;
14    }
15
16public:
17    Node* cloneGraph(Node* node) {
18        unordered_map<Node*, Node*> mpp;
19        return func(node, mpp);
20    }
21};