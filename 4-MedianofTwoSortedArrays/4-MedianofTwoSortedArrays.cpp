// Last updated: 8/12/2026, 9:32:44 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        int total = n + m;
7        int i = 0, j = 0;
8        int prev = 0, curr = 0;
9        int cnt = 0;
10        while (cnt <= total / 2) {
11            prev = curr;
12            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
13                curr = nums1[i];
14                i++;
15            } else {
16                curr = nums2[j];
17                j++;
18            }
19
20            cnt++;
21        }
22
23        if (total % 2 == 1)
24            return curr;
25
26        return (prev + curr) / 2.0;
27    }
28};