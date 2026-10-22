// Last updated: 10/22/2026, 2:54:02 PM
1class Solution {
2public:
3    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        vector<int> prev(m + 1, 0);
7        vector<int> curr(m + 1, 0);
8
9        for (int i = n - 1; i >= 0; i--) {
10            for (int j = m - 1; j >= 0; j--) {
11                if (nums1[i] == nums2[j]) {
12                    curr[j] = 1 + prev[j + 1];
13                }
14                else curr[j] = max(prev[j], curr[j + 1]);
15            }
16            prev = curr;
17        }
18        return prev[0];
19    }
20};