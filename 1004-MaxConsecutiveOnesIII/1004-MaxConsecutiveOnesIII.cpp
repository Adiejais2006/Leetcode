// Last updated: 7/19/2026, 11:50:19 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        int zeroes = 0;
8        int ans = 0;
9        while (r < n) {
10            if (nums[r] == 0)
11                zeroes++;
12            while (zeroes > k) {
13                if (nums[l] == 0)
14                    zeroes--;
15                l++;
16            }
17            ans = max(ans, r - l + 1);
18            r++;
19        }
20        return ans;
21    }
22};