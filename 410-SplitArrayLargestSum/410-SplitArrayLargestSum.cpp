// Last updated: 11/9/2026, 4:25:06 PM
1class Solution {
2    int stduent(const vector<int>& a, int maxSum) {
3        int subarrays = 1;
4        int currentSum = 0;
5        for (int num : a) {
6            if (currentSum + num <= maxSum) {
7                currentSum += num;
8            } else {
9                subarrays++;
10                currentSum = num;
11            }
12        }
13        return subarrays;
14    }
15
16public:
17    int splitArray(vector<int>& a, int k) {
18        int ans = -1;
19        int low = *max_element(a.begin(), a.end());
20        int high = accumulate(a.begin(), a.end(), 0);
21        while (low <= high) {
22            int mid = (low + high) / 2;
23            int val = stduent(a, mid);
24            if (val > k) {
25                low = mid + 1;
26            } else if (val <= k) {
27                ans = mid;
28                high = mid - 1;
29            }
30        }
31        return ans;
32    }
33};