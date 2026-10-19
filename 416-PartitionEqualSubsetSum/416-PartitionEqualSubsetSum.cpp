// Last updated: 10/19/2026, 12:00:36 PM
1class Solution {
2public:
3    bool canPartition(vector<int>& nums) {
4        int sum = 0;
5        int n = nums.size();
6        for (int i = 0; i < n; i++)
7            sum += nums[i];
8        if (sum % 2 == 1)
9            return false;
10        vector<int> prev(sum / 2 + 1, 0);
11        vector<int> curr(sum / 2 + 1, 0);
12        prev[0] = 1;
13        if (nums[0] <= sum / 2) {
14            prev[nums[0]] = true;
15        }
16        for (int i = 1; i < n; i++) {
17            for (int target = 0; target <= sum / 2; target++) {
18                bool nottake = prev[target];
19                bool take = 0;
20                if (target >= nums[i])
21                    take = prev[target - nums[i]];
22                curr[target] = take || nottake;
23            }
24            prev = curr;
25        }
26        return prev[sum / 2];
27    }
28};