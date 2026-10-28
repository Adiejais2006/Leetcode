// Last updated: 10/28/2026, 10:01:12 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int n = s.size();
5        int ans = 0;
6        int l = 0;
7        int r = 0;
8        vector<int> hash(26, 0);
9        int mostoccur = 0;
10        while (r < n) {
11            hash[s[r] - 'A']++;
12            mostoccur = max(mostoccur, hash[s[r] - 'A']);
13            if ((r - l + 1) - mostoccur > k) {
14                hash[s[l++]-'A']--;
15            }
16            ans = max(ans, (r - l + 1));
17            r++;
18        }
19        return ans;
20    }
21};