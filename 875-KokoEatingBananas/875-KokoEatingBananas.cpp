// Last updated: 7/21/2026, 12:40:28 AM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4        int maxu = INT_MIN;
5        for (auto it : piles) {
6            maxu = max(maxu, it);
7        }
8        int low = 1;
9        int high = maxu;
10        int ans = INT_MAX;
11        while (low <= high) {
12            int mid = low + (high - low) / 2;
13            long long hrs = 0;
14            ;
15            for (auto it : piles) {
16                hrs += (it + mid - 1) / mid;
17            }
18            if (hrs > h) {
19                low = mid + 1;
20            } else {
21                high = mid - 1;
22            }
23        }
24        return low;
25    }
26};