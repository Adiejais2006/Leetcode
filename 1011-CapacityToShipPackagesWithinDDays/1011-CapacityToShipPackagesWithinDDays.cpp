// Last updated: 10/26/2026, 3:32:04 PM
1class Solution {
2    int dayteller(vector<int>& weights, int shipcap) {
3        int n = weights.size();
4        int sum = 0;
5        int cnt = 1;
6        for (int i = 0; i < n; i++) {
7            sum += weights[i];
8            if (sum > shipcap) {
9                cnt++;
10                sum = weights[i];
11            }
12        }
13        return cnt;
14    }
15
16public:
17    int shipWithinDays(vector<int>& weights, int days) {
18        int n = weights.size();
19        int maxu = -1;
20        int sum = 0;
21        for (int i = 0; i < n; i++) {
22            maxu = max(maxu, weights[i]);
23            sum += weights[i];
24        }
25        int l = maxu;
26        int h = sum;
27        while (l <= h) {
28            int mid = l + (h - l) / 2;
29            int totalDays = dayteller(weights,mid);
30            if (totalDays > days) {
31                l = mid + 1;
32            } else
33                h = mid - 1;
34        }
35        return l;
36    }
37};