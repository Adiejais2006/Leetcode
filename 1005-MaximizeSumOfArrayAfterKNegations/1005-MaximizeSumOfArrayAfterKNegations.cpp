// Last updated: 11/13/2026, 1:41:40 PM
1class Solution {
2public:
3    int largestSumAfterKNegations(vector<int>& nums, int k) {
4        int n = nums.size();
5        sort(nums.begin(), nums.end());
6        for (int i = 0; i < n; i++) {
7            if (k == 0)
8                break;
9            if (nums[i] < 0) {
10                nums[i] = -nums[i];
11                k--;
12            }
13        }
14        int sum = 0;
15        if (k % 2 == 1) {
16            k = k % 2;
17            priority_queue<int> pq;
18            for (int i = 0; i < k; i++)
19                pq.push(i);
20            for (int i = k; i < n; i++) {
21                if (nums[pq.top()] > nums[i]) {
22                    pq.pop();
23                    pq.push(i);
24                }
25            }
26            for (auto it : nums) {
27                sum += it;
28            }
29            while (!pq.empty()) {
30                sum += -2 * nums[pq.top()];
31                pq.pop();
32            }
33        } else {
34            for (auto it : nums) {
35                sum += it;
36            }
37        }
38        return sum;
39    }
40};