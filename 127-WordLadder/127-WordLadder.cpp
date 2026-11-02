// Last updated: 11/2/2026, 3:14:21 PM
1class Solution {
2public:
3    int ladderLength(string beginWord, string endWord,
4                     vector<string>& wordList) {
5        unordered_set<string> st(wordList.begin(), wordList.end());
6        if (!st.count(endWord))
7            return 0;
8        queue<pair<string, int>> q;
9        q.push({beginWord, 1});
10        while (!q.empty()) {
11            auto [word, cnt] = q.front();
12            q.pop();
13            if (word == endWord)
14                return cnt;
15            for (int i = 0; i < word.size(); i++) {
16                char orig = word[i];
17                for (char ch = 'a'; ch <= 'z'; ch++) {
18                    word[i] = ch;
19                    if (st.count(word)) {
20                        q.push({word, cnt + 1});
21                        st.erase(word);
22                    }
23                }
24                word[i] = orig;
25            }
26        }
27
28        return 0;
29    }
30};