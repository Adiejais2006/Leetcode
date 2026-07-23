// Last updated: 7/24/2026, 12:22:41 AM
1class Solution {
2public:
3    vector<int> decrypt(vector<int>& code, int k) {
4        int n = code.size();
5        vector<int> result(n, 0);
6        if (k == 0) return result;
7
8        int start = k > 0 ? 1 : n + k;
9        int end = k > 0 ? k : n - 1;
10        int sum = 0;
11
12        for (int i = start; i <= end; i++) {
13            sum += code[i % n];
14        }
15
16        for (int i = 0; i < n; i++) {
17            result[i] = sum;
18            sum -= code[start % n];
19            start++;
20            end++;
21            sum += code[end % n];
22        }
23        return result;
24    }
25};
26