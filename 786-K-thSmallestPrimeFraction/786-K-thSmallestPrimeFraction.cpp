// Last updated: 7/25/2026, 12:58:44 AM
1class Solution {
2public:
3    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
4        int n = arr.size();
5        double low = 0.0, high = 1.0;
6
7        while (true) {
8            double mid = (low + high) / 2.0;
9
10            int total = 0;
11            int p = 0, q = 1;
12            double best = 0.0;
13
14            int i = -1;
15
16            for (int j = 1; j < n; j++) {
17                while (i + 1 < j &&
18                       (double)arr[i + 1] / arr[j] < mid)
19                    i++;
20
21                total += i + 1;
22
23                if (i >= 0 &&
24                    (double)arr[i] / arr[j] > best) {
25                    best = (double)arr[i] / arr[j];
26                    p = arr[i];
27                    q = arr[j];
28                }
29            }
30
31            if (total == k)
32                return {p, q};
33
34            if (total < k)
35                low = mid;
36            else
37                high = mid;
38        }
39    }
40};