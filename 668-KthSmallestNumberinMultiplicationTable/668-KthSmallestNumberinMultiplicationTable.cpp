// Last updated: 11/4/2026, 7:25:31 PM
1class Solution {
2public:
3    int findKthNumber(int m, int n, int k) {
4        // priority_queue<int> pq;
5        // for (int i = 1; i <= m; i++) {
6        //     for (int j = 1; j <= n; j++) {
7        //         if (pq.size() < k)
8        //             pq.push(i * j);
9        //         else {
10        //             if (pq.top() > i * j) {
11        //                 pq.pop();
12        //                 pq.push(i * j);
13        //             }
14        //         }
15        //     }
16        // }
17        // return pq.top();
18
19
20         int low = 1;
21        int high = m * n;
22
23        while (low < high) {
24            int mid = low + (high - low) / 2;
25            int count = 0;
26            for (int i = 1; i <= m; i++) {
27                count += min(n, mid / i);
28            }
29            if (count >= k) {
30                high = mid;
31            }
32            else {
33                low = mid + 1;
34            }
35        }
36
37        return low;
38    }
39};