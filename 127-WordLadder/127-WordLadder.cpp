// Last updated: 11/2/2026, 3:13:31 PM
1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord,
4                     vector<string>& wordList) {
5        unordered_set<string> st(wordList.begin(), wordList.end());
6        if (!st.count(endWord))
7            return 0;
8        queue<pair<string, int>> q;
9        q.push({beginWord, 1});
10        int ans = INT_MAX;
11        while (!q.empty()) {
12            auto [word, cnt] = q.front();
13            q.pop();
14            if (word == endWord)
15                ans = min(ans, cnt);
16            for (int i = 0; i < word.size(); i++) {
17                char orig = word[i];
18                for (char ch = 'a'; ch <= 'z'; ch++) {
19                    word[i] = ch;
20                    if (st.count(word)) {
21                        q.push({word, cnt + 1});
22                        st.erase(word);
23                    }
24                }
25                word[i] = orig;
26            }
27        }
28
29        return ans == INT_MAX ? 0 : ans;
30    }
31};