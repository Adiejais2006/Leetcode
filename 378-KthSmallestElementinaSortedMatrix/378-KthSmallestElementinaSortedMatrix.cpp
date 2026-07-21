// Last updated: 7/22/2026, 12:15:26 AM
1class Solution {
2    int helper(vector<vector<int>>& matrix, int mid) {
3        int n = matrix.size();
4        int i = n - 1;
5        int j = 0;
6        int cnt = 0;
7        while (i >= 0 && j < n) {
8            if (matrix[i][j] <= mid) {
9                cnt += i + 1;
10                j++;
11            } else {
12                i--;
13            }
14        }
15        return cnt;
16    }
17
18public:
19    int kthSmallest(vector<vector<int>>& matrix, int k) {
20        int n = matrix.size();
21        int low = matrix[0][0];
22        int high = matrix[n - 1][n - 1];
23
24        while (low <= high) {
25            int mid = low + (high - low) / 2;
26
27            int cnt = helper(matrix, mid);
28
29            if (cnt >= k)
30                high = mid - 1;
31            else
32                low = mid + 1;
33        }
34
35        return low;
36    }
37};