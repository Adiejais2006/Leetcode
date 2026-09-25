// Last updated: 9/25/2026, 4:44:18 PM
1class Solution {
2public:
3    vector<char> op;
4    vector<vector<string>> st;
5    void perf() {
6        int x=st.size()-2, y = st.size()-1;
7        if (op.back()=='+'){
8            st[x].reserve(st[x].size()+st[y].size());
9            st[x].insert(st[x].end(), st[y].begin(), st[y].end());
10        }
11        else { 
12            vector<string> nxt;
13            nxt.reserve(st[x].size()*st[y].size());
14            for (const auto& l : st[x]) {
15                for (const auto& r : st[y]) 
16                    nxt.push_back(l+r);
17            }
18            st[x]=move(nxt);
19        }
20        op.pop_back();
21        st.pop_back();
22    }
23    vector<string> braceExpansionII(string& expr) {
24        const int n=expr.size();
25        op.reserve(n);
26        char prv='@', cur;
27        for (int i=0; i<n; i++, prv=cur) {
28            cur = expr[i];
29            switch (cur) {
30            case ',': 
31                while (!op.empty() && op.back() != '{') perf();
32                op.push_back('+');
33                break;
34            case '{':
35                if (prv=='}' || isalpha(prv)) op.push_back('*');
36                op.push_back('{');
37                break;
38            case '}':
39                while (!op.empty() && op.back()!='{') perf();
40                op.pop_back(); 
41                break;
42            default:
43                if (prv=='}') op.push_back('*');
44                string s;
45                for (; i<n && isalpha(expr[i]); i++) s+=expr[i];
46                st.push_back({s});
47                i--;
48                cur=expr[i];
49            }
50        }
51        while (!op.empty()) perf();
52        auto ans=st.front();
53        sort(ans.begin(), ans.end());
54        ans.erase(unique(ans.begin(), ans.end()), ans.end());
55        return ans;
56    }
57};
58auto init = []() {
59    ios::sync_with_stdio(false);
60    cin.tie(nullptr);
61    cout.tie(nullptr);
62    return 'c';
63}();