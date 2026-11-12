// Last updated: 11/12/2026, 7:25:11 PM
1class Solution {
2public:
3    int numMatchingSubseq(string s, vector<string>& words) {
4        vector<int> pos[26];
5        for (int i = 0; i < s.size(); i++) {
6            pos[s[i] - 'a'].push_back(i);
7        }
8        int ans = 0;
9        for (auto &word : words) {
10            int prev = -1;
11            bool valid = true;
12            for (char c : word) {
13                auto &v = pos[c - 'a'];
14                auto it = upper_bound(v.begin(), v.end(), prev);
15                if (it == v.end()) {
16                    valid = false;
17                    break;
18                }
19                prev = *it;
20            }
21            if (valid)
22                ans++;
23        }
24        return ans;
25    }
26};