// Last updated: 8/21/2026, 11:40:06 AM
1class Solution {
2public:
3    long long findKthSmallest(vector<int>& coins, int k) {
4        sort(coins.begin(), coins.end());
5
6        vector<long long> useful;
7
8        for (int coin : coins) {
9            bool redundant = false;
10
11            for (long long prev : useful) {
12                if (coin % prev == 0) {
13                    redundant = true;
14                    break;
15                }
16            }
17
18            if (!redundant) {
19                useful.push_back(coin);
20            }
21        }
22
23        long long high = useful[0] * 1LL * k;
24        long long low = 1;
25
26        int m = useful.size();
27        int totalMasks = 1 << m;
28
29        vector<long long> lcms(totalMasks, 1);
30
31        vector<int> signs(totalMasks, 1);
32
33        for (int mask = 1; mask < totalMasks; ++mask) {
34            long long currentLCM = 1;
35            int bits = 0;
36
37            for (int i = 0; i < m; ++i) {
38                if (mask & (1 << i)) {
39                    long long g = std::gcd(currentLCM, useful[i]);
40
41                    currentLCM = currentLCM / g;
42
43                    if (currentLCM > high / useful[i]) {
44                        currentLCM = high + 1;
45                        break;
46                    }
47
48                    currentLCM *= useful[i];
49                    ++bits;
50                }
51            }
52
53            lcms[mask] = currentLCM;
54
55            signs[mask] = (bits % 2 == 1) ? 1 : -1;
56        }
57
58        auto count = [&](long long x) {
59            long long result = 0;
60
61            for (int mask = 1; mask < totalMasks; ++mask) {
62                if (lcms[mask] <= x) {
63                    result += signs[mask] * (x / lcms[mask]);
64                }
65            }
66
67            return result;
68        };
69
70        while (low < high) {
71            long long mid = low + (high - low) / 2;
72
73            if (count(mid) >= k) {
74                high = mid;
75            } else {
76                low = mid + 1;
77            }
78        }
79
80        return low;
81    }
82};