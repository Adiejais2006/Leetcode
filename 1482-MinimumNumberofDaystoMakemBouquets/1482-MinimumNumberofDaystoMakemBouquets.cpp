// Last updated: 7/21/2026, 2:13:25 PM
1class Solution {
2    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
3        int consecutive = 0;
4        int bouquets = 0;
5        for (int i = 0; i < bloomDay.size(); i++) {
6            if (bloomDay[i] <= day)
7                consecutive++;
8            else
9                consecutive = 0;
10            if (consecutive == k) {
11                bouquets++;
12                consecutive = 0;
13            }
14        }
15        return (bouquets >= m);
16    }
17
18public:
19    int minDays(vector<int>& bloomDay, int m, int k) {
20        int maxu = INT_MIN;
21        int mini = INT_MAX;
22        for (auto it : bloomDay) {
23            maxu = max(maxu, it);
24            mini = min(mini, it);
25        }
26        int low = mini;
27        int high = maxu;
28        if (1LL * m * k > bloomDay.size())
29            return -1;
30        while (low <= high) {
31            int mid = (low + (high - low) / 2);
32            if (canMake(bloomDay, mid, m, k)) {
33                high = mid - 1;
34            } else
35                low = mid + 1;
36        }
37        return low;
38    }
39};