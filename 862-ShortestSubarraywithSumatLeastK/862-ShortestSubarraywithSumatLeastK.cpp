// Last updated: 11/3/2026, 10:17:21 PM
1class Solution {
2public:
3    int shortestSubarray(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<long long> prefix(n + 1, 0);
6        for (int i = 0; i < n; i++) {
7            prefix[i + 1] = prefix[i] + nums[i];
8        }
9        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
10        int ans = n + 1;
11        for (int i = 0; i <= n; i++) {
12            while (!pq.empty() && prefix[i] - pq.top().first >= k) {
13                ans = min(ans, i - pq.top().second); 
14                pq.pop(); 
15            }
16            pq.push({prefix[i], i});
17        }
18        return ans == n + 1 ? -1 : ans; 
19    }
20};
21