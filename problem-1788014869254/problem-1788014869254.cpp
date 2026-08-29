// Last updated: 8/29/2026, 8:17:49 PM
1class Solution {
2public:
3    int maxValidSplits(vector<int>& nums) {
4        vector<int> copy = nums;
5
6        int n = nums.size();
7        if (n <= 1) return 0;
8
9        vector<int> prefix(n);
10        prefix[0] = nums[0];
11
12        for (int i = 1; i < n; i++)
13            prefix[i] = gcd(prefix[i - 1], nums[i]);
14
15        vector<int> suffix(n);
16        suffix[n - 1] = nums[n - 1];
17
18        for (int i = n - 2; i >= 0; i--)
19            suffix[i] = gcd(suffix[i + 1], nums[i]);
20
21        int log = 0;
22        while ((1 << log) <= n) log++;
23
24        vector<vector<int>> table(n, vector<int>(log));
25
26        for (int i = 0; i < n; i++)
27            table[i][0] = nums[i];
28
29        for (int j = 1; j < log; j++) {
30            for (int i = 0; i + (1 << j) <= n; i++) {
31                table[i][j] = gcd(
32                    table[i][j - 1],
33                    table[i + (1 << (j - 1))][j - 1]
34                );
35            }
36        }
37
38        vector<int> logs(n + 1, 0);
39
40        for (int i = 2; i <= n; i++)
41            logs[i] = logs[i / 2] + 1;
42
43        auto query = [&](int l, int r) -> int {
44            if (l > r) return 0;
45
46            int j = logs[r - l + 1];
47
48            return gcd(
49                table[l][j],
50                table[r - (1 << j) + 1][j]
51            );
52        };
53
54        int answer = 0;
55
56        int total = prefix[n - 1];
57
58        int low = 0, high = n - 1;
59        int first = n - 1;
60
61        while (low <= high) {
62            int mid = low + (high - low) / 2;
63
64            if (prefix[mid] == total) {
65                first = mid;
66                high = mid - 1;
67            } else {
68                low = mid + 1;
69            }
70        }
71
72        low = 0;
73        high = n - 1;
74
75        int last = 0;
76
77        while (low <= high) {
78            int mid = low + (high - low) / 2;
79
80            if (suffix[mid] == total) {
81                last = mid;
82                low = mid + 1;
83            } else {
84                high = mid - 1;
85            }
86        }
87
88        answer = max(answer, last - first);
89
90        int size = n - 1;
91
92        if (size > 1) {
93            for (int remove = 0; remove < n; remove++) {
94
95                int left = remove > 0 ? prefix[remove - 1] : 0;
96                int right = remove < n - 1 ? suffix[remove + 1] : 0;
97
98                int target = gcd(left, right);
99
100                low = 0;
101                high = size - 1;
102
103                int firstPosition = size - 1;
104
105                while (low <= high) {
106                    int mid = low + (high - low) / 2;
107
108                    int current;
109
110                    if (mid < remove) {
111                        current = prefix[mid];
112                    } else {
113                        current = gcd(
114                            left,
115                            query(remove + 1, mid + 1)
116                        );
117                    }
118
119                    if (current == target) {
120                        firstPosition = mid;
121                        high = mid - 1;
122                    } else {
123                        low = mid + 1;
124                    }
125                }
126
127                low = 0;
128                high = size - 1;
129
130                int lastPosition = 0;
131
132                while (low <= high) {
133                    int mid = low + (high - low) / 2;
134
135                    int current;
136
137                    if (mid >= remove) {
138                        current = suffix[mid + 1];
139                    } else {
140                        current = gcd(
141                            query(mid, remove - 1),
142                            right
143                        );
144                    }
145
146                    if (current == target) {
147                        lastPosition = mid;
148                        low = mid + 1;
149                    } else {
150                        high = mid - 1;
151                    }
152                }
153
154                answer = max(
155                    answer,
156                    lastPosition - firstPosition
157                );
158            }
159        }
160
161        return answer;
162    }
163};