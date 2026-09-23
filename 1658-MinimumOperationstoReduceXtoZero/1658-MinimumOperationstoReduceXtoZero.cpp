// Last updated: 9/23/2026, 2:28:53 PM
1class Solution {
2public:
3    int minOperations(vector<int>& A, int x) {
4        int k = reduce(A.begin(), A.end()) - x, n = A.size();
5        if (k < 0) return -1;
6        if (k == 0) return n;
7
8        int best = -1, i = 0, sum = 0;
9        for (int j = 0; j < n; j++) {
10            sum += A[j];
11            while (sum > k)
12                sum -= A[i++];
13
14            if (sum == k)
15                best = max(best, j - i + 1);
16        }
17
18        return best + 1 ? n - best : -1;
19    }
20};