// Last updated: 11/5/2026, 2:15:34 PM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int ans = 0;
5        int n = arr1.size();
6        int m = arr2.size();
7
8        for (int i = 0; i < n; i++) {
9            bool found = false;
10            for (int j = 0; j < m; j++) {
11                if (abs(arr1[i] - arr2[j]) <= d) {
12                    found = true;
13                    break;
14                }
15            }
16            if (!found)
17                ans++;
18        }
19        return ans;
20    }
21};