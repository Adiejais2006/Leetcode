// Last updated: 10/21/2026, 9:57:04 PM
1class Solution {
2    int func(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
3        if (i == s.size())
4            return dp[i] = true;
5        if (dp[i] != -1)
6            return dp[i];
7        string a = "";
8        for (int k = i; k < s.size(); k++) {
9            a += s[k];
10            if (st.count(a)) {
11                if (func(k + 1, s, st, dp))
12                    return dp[i] = true;
13            }
14        }
15        return dp[i] = false;
16    }
17
18public:
19    bool wordBreak(string s, vector<string>& wordDict) {
20        int n = s.size();
21        unordered_set<string> st;
22        for (auto it : wordDict)
23            st.insert(it);
24        vector<int> dp(n + 1, -1);
25        return func(0, s, st, dp);
26    }
27};