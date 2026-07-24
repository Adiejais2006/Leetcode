// Last updated: 7/25/2026, 12:41:51 AM
1class Solution {
2public:
3    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
4        priority_queue<tuple<double, int, int>> pq;
5        int n = nums.size();
6        for (int i = 0; i < n; i++) {
7            for (int j = i + 1; j < n; j++) {
8                double current = (double)nums[i] / nums[j];
9                if (pq.size() < k)
10                    pq.push({current, nums[i], nums[j]});
11                else {
12                    if (!pq.empty() && get<0>(pq.top()) > current) {
13                        pq.pop();
14                        pq.push({current, nums[i], nums[j]});
15                    }
16                }
17            }
18        }
19
20      
21    
22       return {get<1>(pq.top()) ,get<2>(pq.top())};
23      
24      
25    }
26};