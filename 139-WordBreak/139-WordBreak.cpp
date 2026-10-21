// Last updated: 10/21/2026, 9:59:11 PM
1class Solution {
2
3public:
4    bool wordBreak(string s, vector<string>& wordDict) {
5        int n = s.size();
6        unordered_set<string> st;
7        for (auto it : wordDict)
8            st.insert(it);
9        vector<int> dp(n + 1, 0);
10        dp[n] = true;
11        for (int i = n; i >= 0; i--) {
12            string a = "";
13            for (int k = i; k < s.size(); k++) {
14                a += s[k];
15                if (st.count(a)) {
16                    if (dp[k + 1])
17                        dp[i] = true;
18                }
19            }
20        }
21        return dp[0];
22    }
23};