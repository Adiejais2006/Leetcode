// Last updated: 11/3/2026, 12:06:27 AM
1class Solution {
2public:
3    int ans = 0;
4    void solve(vector<int>& freq) {
5        for (int i = 0; i < 26; i++) {
6            if (freq[i] == 0) continue;
7            // Use this character
8            ans++;
9            freq[i]--;
10            solve(freq);
11            // Backtrack
12            freq[i]++;
13        }
14    }
15    int numTilePossibilities(string tiles) {
16        vector<int> freq(26, 0);
17        for (char ch : tiles) {
18            freq[ch - 'A']++;
19        }
20        solve(freq);
21        return ans;
22    }
23};