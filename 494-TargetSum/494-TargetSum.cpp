// Last updated: 10/20/2026, 3:59:09 PM
1class Solution {
2public:
3    int findTargetSumWays(vector<int>& arr, int target) {
4        int n = arr.size();
5         int sum = 0;
6        for (auto it : arr) sum += it;
7        if (sum - target < 0 || (sum - target) % 2 != 0) return 0;
8        int K = (sum - target) / 2;
9        int mod = 1e9 + 7;
10        vector<int> before(K + 1, 0);
11        vector<int> curr(K + 1, 0);
12
13        if (arr[0] == 0) {
14            before[0] = 2;
15        } else
16            before[0] = 1;
17        if (arr[0] != 0 && arr[0] <= K) before[arr[0]] = 1;
18        for (int ind = 1; ind < n; ind++) {
19            for (int target = 0; target <= K; target++) {
20                int pick = 0;
21                if (arr[ind] <= target) pick = before[target - arr[ind]];
22
23                int notpick = before[target];
24
25                curr[target] = (pick + notpick) % mod;
26            }
27            before = curr;
28        }
29        return before[K];
30    }
31};