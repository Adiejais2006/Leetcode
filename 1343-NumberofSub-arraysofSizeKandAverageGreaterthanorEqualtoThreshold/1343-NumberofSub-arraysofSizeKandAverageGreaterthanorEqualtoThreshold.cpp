// Last updated: 10/18/2026, 9:01:46 PM
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int n = arr.size();
5        int l = 0;
6        int r = 0;
7        int sum = 0;
8        while (r < k) {
9            sum += arr[r++];
10        }
11        int ans = 0;
12        if (sum / (r - l) >= threshold)
13            ans++;
14        while (l < r && r < n) {
15            sum -= arr[l];
16            sum += arr[r];
17            int avg = (sum) / (r - l);
18            if (avg >= threshold)
19                ans++;
20            l++;
21            r++;
22        }
23        return ans;
24    }
25};