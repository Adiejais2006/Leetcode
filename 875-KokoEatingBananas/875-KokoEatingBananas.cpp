// Last updated: 10/27/2026, 3:08:44 PM
1class Solution {
2    int hrteller(int number, vector<int>& piles) {
3        int time = 0;
4        int sum = 0;
5        for (int i = 0; i < piles.size(); i++) {
6            time += ((piles[i] + number - 1) / number);
7        }
8        return time;
9    }
10
11public:
12    int minEatingSpeed(vector<int>& piles, int h) {
13        int n = piles.size();
14        int maxu = 0;
15        for (auto it : piles)
16            maxu = max(maxu, it);
17        int low = 1;
18        int high = maxu;
19        int ans = INT_MAX;
20        while (low <= high) {
21            int mid = low + (high - low) / 2;
22            int consumehours = hrteller(mid, piles);
23            if (consumehours > h) {
24                low = mid + 1;
25            } else {
26                ans = min(ans, mid);
27                high = mid - 1;
28            }
29        }
30        return ans;
31    }
32};