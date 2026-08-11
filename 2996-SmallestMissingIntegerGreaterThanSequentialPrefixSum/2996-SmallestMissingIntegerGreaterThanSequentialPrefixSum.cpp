// Last updated: 8/11/2026, 7:56:21 PM
1class Solution {
2public:
3    int missingInteger(vector<int>& A) {
4        int n = A.size();
5        unordered_set<int> seen(A.begin(), A.end());
6        int sum = A[0];
7
8        for (int i = 1; i < n; i++) {
9            if (A[i] == A[i - 1] + 1) sum += A[i];
10            else break;
11        }
12
13        while (seen.count(sum))
14            sum++;
15
16        return sum;
17    }
18};