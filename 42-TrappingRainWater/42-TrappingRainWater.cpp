// Last updated: 9/2/2026, 11:14:10 PM
1class Solution {
2public:
3    int trap(vector<int>& height) {
4        int n = height.size();
5        vector<int> lmax(n);
6        vector<int> rmax(n);
7        lmax[0] = height[0];
8        for (int i = 1; i < n; i++) {
9            lmax[i] = max(lmax[i - 1], height[i]);
10        }
11        rmax[n - 1] = height[n - 1];
12        for (int i = n - 2; i >= 0; i--) {
13            rmax[i] = max(rmax[i + 1], height[i]);
14        }
15        int ans = 0;
16        for (int i = 0; i < n; i++) {
17            int water = min(lmax[i], rmax[i]) - height[i];
18            ans += water;
19        }
20
21        return ans;
22    }
23};