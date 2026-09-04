// Last updated: 9/4/2026, 3:07:15 PM
1    class Solution {
2    public:
3        int firstStableIndex(vector<int>& nums, int k) {
4            int n = nums.size();
5            vector<int> prefixMax(n);
6            vector<int> prefixMin(n);
7            prefixMax[0] = nums[0];
8            prefixMin[n - 1] = nums[n - 1];
9            for (int i = 1; i < n; i++) {
10                prefixMax[i] = max(nums[i], prefixMax[i - 1]);
11                prefixMin[n - i - 1] = min(nums[n - i - 1], prefixMin[n - i]);
12            }
13            for (int i = 0; i < n; i++) {
14                int val = prefixMax[i] - prefixMin[i];
15                if (val <= k) {
16                    return i;
17                }
18            }
19            return -1;
20        }
21    };