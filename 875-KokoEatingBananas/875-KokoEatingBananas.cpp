// Last updated: 10/27/2026, 3:10:26 PM
1class Solution {
2    long long hrteller(int number, vector<int>& piles) {
3        long long time = 0;
4        for (int i = 0; i < piles.size(); i++) {
5            time += ((piles[i] + number - 1) / number);
6        }
7        return time;
8    }
9
10public:
11    int minEatingSpeed(vector<int>& piles, int h) {
12        int n = piles.size();
13        int maxu = 0;
14        for (auto it : piles)
15            maxu = max(maxu, it);
16        int low = 1;
17        int high = maxu;
18        int ans = INT_MAX;
19        while (low <= high) {
20            int mid = low + (high - low) / 2;
21            long long consumehours = hrteller(mid, piles);
22            if (consumehours > h) {
23                low = mid + 1;
24            } else {
25                ans = min(ans, mid);
26                high = mid - 1;
27            }
28        }
29        return ans;
30    }
31};