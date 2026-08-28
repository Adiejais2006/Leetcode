// Last updated: 8/28/2026, 6:44:38 PM
1class Solution {
2public:
3    string lexPalindromicPermutation(string str, string target) {
4        int freq[26] = {0};
5        for (char s : str)
6            freq[s - 'a']++;
7
8        char center = 0;
9        for (int i = 0; i < 26; i++) {
10            if (freq[i] % 2) {
11                if (center != 0)
12                    return "";
13                center = 'a' + i;
14                freq[i]--;
15            }
16        }
17
18        int sz = str.length();
19        int half = sz / 2;
20        for (int i = 0; i < half; i++)
21            freq[target[i] - 'a'] -= 2;
22
23        if (check(freq)) {
24            string head = target.substr(0, half);
25            string rev = head;
26            reverse(rev.begin(), rev.end());
27            string tail = "";
28            if (center != 0)
29                tail += center;
30            tail += rev;
31            if (tail > target.substr(half))
32                return head + tail;
33        }
34
35        for (int i = half - 1; i >= 0; i--) {
36            char w = target[i];
37            freq[w - 'a'] += 2;
38            if (!check(freq))
39                continue;
40
41            for (int j = (w - 'a') + 1; j < 26; j++) {
42                if (freq[j] == 0)
43                    continue;
44                freq[j] -= 2;
45                string result = target.substr(0, i + 1);
46                result[i] = 'a' + j;
47
48                for (int k = 0; k < 26; k++) {
49                    int cnt = freq[k] / 2;
50                    if (cnt > 0)
51                        result.append(cnt, 'a' + k);
52                }
53
54                string part = result;
55                reverse(part.begin(), part.end());
56                if (center != 0)
57                    result.push_back(center);
58                result += part;
59                return result;
60            }
61        }
62
63        return "";
64    }
65
66    bool check(int f[]) {
67        for (int i = 0; i < 26; i++)
68            if (f[i] < 0)
69                return false;
70        return true;
71    }
72};