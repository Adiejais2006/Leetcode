// Last updated: 8/7/2026, 4:14:09 PM
1class Solution {
2public:
3    string smallestNumber(string num, long long t) {
4        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
5        long long temp = t;
6        while (temp % 2 == 0) { temp /= 2; req2++; }
7        while (temp % 3 == 0) { temp /= 3; req3++; }
8        while (temp % 5 == 0) { temp /= 5; req5++; }
9        while (temp % 7 == 0) { temp /= 7; req7++; }
10        if (temp > 1) return "-1";
11
12        int dp[60][40];
13        for (int i = 0; i < 60; ++i) {
14            for (int j = 0; j < 40; ++j) {
15                dp[i][j] = 1e9;
16            }
17        }
18        dp[0][0] = 0;
19        
20        int trans[6][2] = {{1, 0}, {0, 1}, {2, 0}, {1, 1}, {3, 0}, {0, 2}};
21        for (int i = 0; i < 60; ++i) {
22            for (int j = 0; j < 40; ++j) {
23                if (dp[i][j] == 1e9) continue;
24                for (auto& tr : trans) {
25                    int ni = min(59, i + tr[0]);
26                    int nj = min(39, j + tr[1]);
27                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + 1);
28                }
29            }
30        }
31        for (int i = 59; i >= 0; --i) {
32            for (int j = 39; j >= 0; --j) {
33                if (i < 59) dp[i][j] = min(dp[i][j], dp[i + 1][j]);
34                if (j < 39) dp[i][j] = min(dp[i][j], dp[i][j + 1]);
35            }
36        }
37
38        int F2[] = {0, 0, 1, 0, 2, 0, 1, 0, 3, 0};
39        int F3[] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 2};
40        int F5[] = {0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
41        int F7[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
42
43        int n = num.length();
44        bool has_zero = false;
45        int first_zero = n;
46        for (int i = 0; i < n; ++i) {
47            if (num[i] == '0') {
48                has_zero = true;
49                first_zero = i;
50                break;
51            }
52        }
53
54        if (!has_zero) {
55            int r2 = req2, r3 = req3, r5 = req5, r7 = req7;
56            for (char c : num) {
57                int d = c - '0';
58                r2 = max(0, r2 - F2[d]);
59                r3 = max(0, r3 - F3[d]);
60                r5 = max(0, r5 - F5[d]);
61                r7 = max(0, r7 - F7[d]);
62            }
63            if (r2 == 0 && r3 == 0 && r5 == 0 && r7 == 0) return num;
64        }
65
66        int limit = min(n - 1, first_zero);
67        int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
68        for (int i = 0; i < limit; ++i) {
69            int d = num[i] - '0';
70            p2 += F2[d];
71            p3 += F3[d];
72            p5 += F5[d];
73            p7 += F7[d];
74        }
75
76        for (int i = limit; i >= 0; --i) {
77            int start_d = (num[i] - '0') + 1;
78            for (int d = start_d; d <= 9; ++d) {
79                int n2 = max(0, req2 - p2 - F2[d]);
80                int n3 = max(0, req3 - p3 - F3[d]);
81                int n5 = max(0, req5 - p5 - F5[d]);
82                int n7 = max(0, req7 - p7 - F7[d]);
83                int L = n - 1 - i;
84                
85                if (n7 + n5 + dp[n2][n3] <= L) {
86                    string ans = num.substr(0, i) + to_string(d);
87                    int rem2 = n2, rem3 = n3, rem5 = n5, rem7 = n7;
88                    for (int pos = 0; pos < L; ++pos) {
89                        for (int x = 1; x <= 9; ++x) {
90                            int nn2 = max(0, rem2 - F2[x]);
91                            int nn3 = max(0, rem3 - F3[x]);
92                            int nn5 = max(0, rem5 - F5[x]);
93                            int nn7 = max(0, rem7 - F7[x]);
94                            if (nn7 + nn5 + dp[nn2][nn3] <= L - 1 - pos) {
95                                ans += to_string(x);
96                                rem2 = nn2; rem3 = nn3; rem5 = nn5; rem7 = nn7;
97                                break;
98                            }
99                        }
100                    }
101                    return ans;
102                }
103            }
104            if (i > 0) {
105                int d = num[i - 1] - '0';
106                p2 -= F2[d];
107                p3 -= F3[d];
108                p5 -= F5[d];
109                p7 -= F7[d];
110            }
111        }
112
113        int min_len_needed = req7 + req5 + dp[req2][req3];
114        int M = max(n + 1, min_len_needed);
115        string ans = "";
116        int rem2 = req2, rem3 = req3, rem5 = req5, rem7 = req7;
117        
118        for (int pos = 0; pos < M; ++pos) {
119            for (int x = 1; x <= 9; ++x) {
120                int nn2 = max(0, rem2 - F2[x]);
121                int nn3 = max(0, rem3 - F3[x]);
122                int nn5 = max(0, rem5 - F5[x]);
123                int nn7 = max(0, rem7 - F7[x]);
124                if (nn7 + nn5 + dp[nn2][nn3] <= M - 1 - pos) {
125                    ans += to_string(x);
126                    rem2 = nn2; rem3 = nn3; rem5 = nn5; rem7 = nn7;
127                    break;
128                }
129            }
130        }
131        return ans;
132    }
133};