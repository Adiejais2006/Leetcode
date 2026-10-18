// Last updated: 10/18/2026, 6:40:31 PM
1class Solution {
2public:
3    int minDeletions(vector<int>& nums) {
4        int n = nums.size();
5        int i = 0;
6        int ans = 0;
7        while (i < n - 1) {
8            int j = i + 1;
9            if (nums[i] != nums[j]) {
10                i++;
11                j++;
12            } else {
13                int cnt = 0;
14                while ( i < n-1 && nums[i] == nums[i + 1]) {
15                    cnt++;
16                    i++;
17                }
18                ans += cnt;
19            }
20        }
21        return ans;
22    }
23};