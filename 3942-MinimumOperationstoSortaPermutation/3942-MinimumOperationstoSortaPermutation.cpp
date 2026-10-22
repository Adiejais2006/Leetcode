// Last updated: 10/22/2026, 12:28:57 PM
1class Solution {
2public:
3    int minOperations(auto& A) {
4        int n = A.size();
5        int asc = 1, dsc = 1;
6
7        for (int i = 1; i < n; i++) {
8            asc += A[i] == (A[i - 1] + 1) % n;
9            dsc += A[i - 1] == (A[i] + 1) % n;
10        }
11
12        if (asc == n)
13            return A.front() ? min(n - A.front(), A.front() + 2) : 0;
14
15        if (dsc == n)
16            return min(n - A.back(), A.back()) + 1;
17
18        return -1;
19    }
20};