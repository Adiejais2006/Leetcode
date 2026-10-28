// Last updated: 10/28/2026, 9:43:21 PM
1class Solution {
2    int helper(int days, vector<int>& bloomDay, int m, int k) {
3        int n = bloomDay.size();
4        int sum = 0;
5        int ans = 0;
6        for (int i = 0; i < n; i++) {
7            if (bloomDay[i] <= days) {
8                sum++;
9            } else {
10                sum = 0;
11            }
12            if (sum == k) {
13                sum = 0;
14                ans++;
15            }
16        }
17        return ans;
18    }
19
20public:
21    int minDays(vector<int>& bloomDay, int m, int k) {
22        int n = bloomDay.size();
23        if ((long long)m * k > n)
24            return -1;
25        int low = 1;
26        int high = 0;
27        for (auto it : bloomDay)
28            high = max(high, it);
29        while (low <= high) {
30            int mid = low + (high - low) / 2;
31            int bouquets = helper(mid, bloomDay, m, k);
32            if (bouquets < m) {
33                low = mid + 1;
34            } else
35                high = mid - 1;
36        }
37        return low;
38    }
39};