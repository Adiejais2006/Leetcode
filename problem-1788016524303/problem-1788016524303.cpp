// Last updated: 8/29/2026, 8:45:24 PM
1class Solution {
2    int getGcd(const vector<vector<int>>& table, int left, int right) {
3        if (left > right)
4            return 0;
5
6        int len = right - left + 1;
7        int level = (int)log2(len);
8
9        return gcd(
10            table[level][left],
11            table[level][right - (1 << level) + 1]
12        );
13    }
14
15    int gcdSkip(
16        const vector<vector<int>>& table,
17        int left,
18        int right,
19        int removed
20    ) {
21        if (removed < left || removed > right)
22            return getGcd(table, left, right);
23
24        return gcd(
25            getGcd(table, left, removed - 1),
26            getGcd(table, removed + 1, right)
27        );
28    }
29
30public:
31    int maxValidSplits(vector<int>& nums) {
32        int n = nums.size();
33
34        if (n <= 1)
35            return 0;
36
37        int levels = (int)log2(n) + 1;
38        vector<vector<int>> table(levels, vector<int>(n));
39
40        for (int i = 0; i < n; i++)
41            table[0][i] = nums[i];
42
43        for (int level = 1; level < levels; level++) {
44            int len = 1 << level;
45
46            for (int i = 0; i + len <= n; i++) {
47                table[level][i] = gcd(
48                    table[level - 1][i],
49                    table[level - 1][i + len / 2]
50                );
51            }
52        }
53
54        int answer = 0;
55
56        for (int removed = -1; removed < n; removed++) {
57            int totalGcd;
58
59            if (removed == -1) {
60                totalGcd = getGcd(table, 0, n - 1);
61            } else {
62                totalGcd = gcd(
63                    getGcd(table, 0, removed - 1),
64                    getGcd(table, removed + 1, n - 1)
65                );
66            }
67
68            int size = n - (removed != -1);
69
70            if (size <= 1)
71                continue;
72
73            int first = size;
74            int low = 0;
75            int high = size - 1;
76
77            while (low <= high) {
78                int mid = low + (high - low) / 2;
79
80                int index = mid;
81
82                if (removed != -1 && mid >= removed)
83                    index++;
84
85                if (gcdSkip(table, 0, index, removed) == totalGcd) {
86                    first = mid;
87                    high = mid - 1;
88                } else {
89                    low = mid + 1;
90                }
91            }
92
93            int last = -1;
94            low = 0;
95            high = size - 1;
96
97            while (low <= high) {
98                int mid = low + (high - low) / 2;
99
100                int index = mid;
101
102                if (removed != -1 && mid >= removed)
103                    index++;
104
105                if (gcdSkip(table, index, n - 1, removed) == totalGcd) {
106                    last = mid;
107                    low = mid + 1;
108                } else {
109                    high = mid - 1;
110                }
111            }
112
113            if (first <= last)
114                answer = max(answer, last - first);
115        }
116
117        return answer;
118    }
119};