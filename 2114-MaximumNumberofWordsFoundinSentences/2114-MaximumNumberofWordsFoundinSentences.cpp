// Last updated: 11/1/2026, 2:28:57 PM
1class Solution {
2public:
3    int mostWordsFound(vector<string>& sentences) {
4        int ans = 0;
5        for (auto it : sentences) {
6            stringstream ss(it);
7            string word;
8            int cnt = 0;
9            while (ss >> word) {
10                cnt++;
11            }
12            ans = max(ans, cnt);
13        }
14        return ans;
15    }
16};