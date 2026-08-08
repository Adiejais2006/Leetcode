// Last updated: 8/8/2026, 9:32:36 PM
1class Solution {
2public:
3    vector<int> validSequence(string word1, string word2) {
4        int N = word1.size();
5        int M = word2.size();
6        int R = M - 1;
7        int C = 0;
8        vector<int> Right(N);
9        for (int i = N - 1; i >= 0; i--) {
10            Right[i] = C;
11            if (R >= 0 && word1[i] == word2[R]) {
12                R--;
13                C++;
14            }
15        }
16
17        vector<int> ans;
18        bool changed = false;
19        int j = 0;
20
21        for (int i = 0; i < N && j < M; i++) {
22            if (word1[i] == word2[j]) {
23                ans.push_back(i);
24                j++;
25            } else if (!changed && Right[i] >= M - 1 - j) {
26
27                ans.push_back(i);
28                j++;
29                changed = true;
30            }
31        }
32
33        if (j == M) {
34            return ans;
35        }
36        return {};
37    }
38};