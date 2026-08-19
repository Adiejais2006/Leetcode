// Last updated: 8/19/2026, 6:22:27 PM
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        unordered_map<int, int> mp;
5        for (auto it : reservedSeats) {
6            int row = it[0];
7            int seat = it[1];
8            if (seat >= 2 && seat <= 9) {
9                mp[row] |= (1 << seat);
10            }
11        }
12        int ans = (n - mp.size()) * 2;
13        int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
14        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
15        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
16        for (auto it : mp) {
17            int reserved = it.second;
18            if ((reserved & left) == 0 &&
19                (reserved & right) == 0) {
20                ans += 2;
21            }
22            else if ((reserved & left) == 0 ||
23                     (reserved & middle) == 0 ||
24                     (reserved & right) == 0) {   
25                ans += 1;
26            }
27        }
28        return ans;
29    }
30};