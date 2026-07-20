// Last updated: 7/21/2026, 12:51:40 AM
1class Solution {
2    int dayscal(vector<int>& weights, int capacity) {
3        int sum = 0;
4        int days = 1;
5        for (auto it : weights) {
6            sum += it;
7            if (sum > capacity) {
8                sum = it;
9                days++;
10            }
11        }
12        return days;
13    }
14
15public:
16    int shipWithinDays(vector<int>& weights, int days) {
17        int n = weights.size();
18        int sum = 0;
19        int maxu = INT_MIN;
20        for (auto it : weights) {
21            maxu = max(maxu, it);
22            sum += it;
23        }
24        int low = maxu;
25        int high = sum;
26
27        while (low <= high) {
28            int mid = low + (high - low) / 2;
29            int totaldays = dayscal(weights, mid);
30            if (totaldays > days) {
31                low = mid + 1;
32            } else
33                high = mid - 1;
34        }
35        return low;
36    }
37};