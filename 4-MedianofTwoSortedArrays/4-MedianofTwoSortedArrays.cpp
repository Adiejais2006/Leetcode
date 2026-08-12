// Last updated: 8/12/2026, 9:33:04 PM
1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6
7        int i = 0;
8        int j = 0;
9
10        int total = n + m;
11        int steps = total / 2;
12
13        int cnt = 0;
14        int prev = 0;
15        int curr = 0;
16
17        while (i < n && j < m && cnt <= steps) {
18
19            prev = curr;
20
21            if (nums1[i] <= nums2[j]) {
22                curr = nums1[i];
23                i++;
24            } else {
25                curr = nums2[j];
26                j++;
27            }
28
29            cnt++;
30        }
31
32        while (i < n && cnt <= steps) {
33
34            prev = curr;
35            curr = nums1[i];
36
37            i++;
38            cnt++;
39        }
40
41        while (j < m && cnt <= steps) {
42
43            prev = curr;
44            curr = nums2[j];
45
46            j++;
47            cnt++;
48        }
49
50        if (total % 2 == 1)
51            return curr;
52
53        return (prev + curr) / 2.0;
54    }
55};