// Last updated: 9/22/2026, 6:16:48 PM
1class Solution {
2public:
3    struct Node {
4        int prod;
5        array<int, 5> freq;
6        Node() : prod(1) { freq.fill(0); }
7    };
8    
9    int k;
10    vector<Node> tree;
11    vector<int> nums;
12    
13    Node merge(const Node& L, const Node& R) {
14        Node res;
15        res.prod = (1LL * L.prod * R.prod) % k;
16        res.freq = L.freq;
17        for (int r = 0; r < k; ++r) {
18            if (R.freq[r]) {
19                int nr = (1LL * L.prod * r) % k;
20                res.freq[nr] += R.freq[r];
21            }
22        }
23        return res;
24    }
25    
26    void build(int v, int tl, int tr) {
27        if (tl == tr) {
28            tree[v].prod = nums[tl] % k;
29            tree[v].freq[tree[v].prod] = 1;
30            return;
31        }
32        int tm = (tl + tr) / 2;
33        build(v * 2, tl, tm);
34        build(v * 2 + 1, tm + 1, tr);
35        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
36    }
37    
38    void update(int v, int tl, int tr, int pos, int val) {
39        if (tl == tr) {
40            tree[v].prod = val % k;
41            tree[v].freq.fill(0);
42            tree[v].freq[tree[v].prod] = 1;
43            return;
44        }
45        int tm = (tl + tr) / 2;
46        if (pos <= tm) update(v * 2, tl, tm, pos, val);
47        else update(v * 2 + 1, tm + 1, tr, pos, val);
48        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
49    }
50    
51    Node query(int v, int tl, int tr, int l, int r) {
52        if (l > r) return Node();
53        if (l == tl && r == tr) return tree[v];
54        int tm = (tl + tr) / 2;
55        return merge(query(v * 2, tl, tm, l, min(r, tm)),
56                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
57    }
58    
59    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
60        this->k = k;
61        this->nums = nums;
62        int n = nums.size();
63        tree.assign(4 * n, Node());
64        build(1, 0, n - 1);
65        vector<int> ans;
66        for (auto& q : queries) {
67            int idx = q[0], val = q[1], start = q[2], x = q[3];
68            update(1, 0, n - 1, idx, val);
69            Node res = query(1, 0, n - 1, start, n - 1);
70            ans.push_back(res.freq[x]);
71        }
72        return ans;
73    }
74};