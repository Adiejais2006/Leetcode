// Last updated: 10/20/2026, 4:31:09 PM
1class Solution {
2
3public:
4    int findTargetSumWays(vector<int>& nums, int target) {
5        int n = nums.size();
6        int sum = 0;
7        for (int x : nums)
8            sum += x;
9        if (abs(target) > sum)
10            return 0;
11        if ((sum - target) % 2 != 0)
12            return 0;
13        int tar = (sum - target) / 2;
14      vector<int> prev(tar+1 , 0);
15      vector<int> curr(tar+1 , 0);
16        for (int i = 0; i <= tar; i++) {
17            if (i == 0 && nums[0] == 0)
18               prev[i] = 2;
19            else if (i == 0 || i == nums[0])
20               prev[i] = 1;
21        }
22        for (int i = 1; i < n; i++) {
23            for (int j = 0; j <= tar; j++) {
24                int notpick = prev[j];
25                int pick = 0;
26                if (j >= nums[i])
27                    pick = prev[j - nums[i]];
28                curr[j] = pick + notpick;
29            }
30            prev = curr;
31        }
32        return prev[tar];
33    }
34};