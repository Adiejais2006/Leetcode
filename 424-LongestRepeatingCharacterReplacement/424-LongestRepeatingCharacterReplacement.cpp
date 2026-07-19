// Last updated: 7/20/2026, 12:41:06 AM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int l = 0;
5        int r = 0;
6        int n = s.size();
7        int ans = 0;
8        unordered_map<int, int> mpp;
9        int mostoccur = 0;
10        while (r < n) {
11            mpp[s[r]]++;
12            mostoccur = max(mostoccur, mpp[s[r]]);
13            while (r - l + 1 - mostoccur > k) {
14                mpp[s[l]]--;
15                l++;
16            }
17            ans = max(ans, r - l + 1);
18            r++;
19        }
20
21        return ans;
22    }
23};