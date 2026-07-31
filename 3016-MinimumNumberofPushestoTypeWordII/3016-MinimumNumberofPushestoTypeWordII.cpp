// Last updated: 7/31/2026, 10:02:20 PM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int> freq(26, 0);
5
6        for (char c : word)
7            freq[c - 'a']++;
8
9        int ans = 0;
10        int assigned = 0;
11
12        while (true) {
13            int mx = 0, idx = -1;
14
15            for (int i = 0; i < 26; i++) {
16                if (freq[i] > mx) {
17                    mx = freq[i];
18                    idx = i;
19                }
20            }
21
22            if (idx == -1) break;
23
24            ans += mx * (assigned / 8 + 1);
25            freq[idx] = 0;
26            assigned++;
27        }
28
29        return ans;
30    }
31};