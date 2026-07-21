// Last updated: 7/21/2026, 1:42:16 PM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        vector<pair<char, int>> runs;
5        string t = "1" + s + "1";
6        char ch = t[0];
7        int cnt = 1;
8        int ones = 0;
9        for (char c : s)
10            if (c == '1')
11                ones++;
12        for (int i = 1; i < t.size(); i++) {
13
14            if (t[i] == ch) {
15                cnt++;
16            } else {
17                runs.push_back({ch, cnt});
18                ch = t[i];
19                cnt = 1;
20            }
21        }
22        runs.push_back({ch, cnt});
23        int ans = ones;
24        for (int i = 1; i < runs.size() - 1; i++) {
25            if (runs[i].first == '1' && runs[i - 1].first == '0' &&
26                runs[i + 1].first == '0') {
27                int gain = runs[i - 1].second + runs[i + 1].second;
28                ans = max(ans, ones + gain);
29            }
30        }
31        return ans;
32    }
33};