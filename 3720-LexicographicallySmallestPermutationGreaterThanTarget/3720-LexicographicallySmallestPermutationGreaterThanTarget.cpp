// Last updated: 8/27/2026, 9:19:42 PM
1class Solution {
2public:
3    string lexGreaterPermutation(string s, string target) {
4        int cnt[26] = {};
5
6        for (char ch : s) {
7            cnt[ch - 'a']++;
8        }
9
10        for (char ch : target) {
11            cnt[ch - 'a']--;
12        }
13
14        for (int i = target.size() - 1; i >= 0; i--) {
15            int cur = target[i] - 'a';
16            cnt[cur]++;
17
18            bool ok = true;
19            for (int c = 0; c < 26; c++) {
20                if (cnt[c] < 0) {
21                    ok = false;
22                    break;
23                }
24            }
25
26            if (!ok) continue;
27
28            int next = -1;
29            for (int c = cur + 1; c < 26; c++) {
30                if (cnt[c] > 0) {
31                    next = c;
32                    break;
33                }
34            }
35
36            if (next == -1) continue;
37
38            cnt[next]--;
39
40            string ans = target.substr(0, i);
41            ans += char('a' + next);
42
43            for (int c = 0; c < 26; c++) {
44                ans.append(cnt[c], char('a' + c));
45            }
46
47            return ans;
48        }
49
50        return "";
51    }
52};