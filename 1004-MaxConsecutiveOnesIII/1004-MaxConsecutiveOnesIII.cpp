// Last updated: 10/23/2026, 12:30:48 PM
1class Solution {
2public:
3    int longestOnes(vector<int>& nums, int k) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        int ans = 0;
8        while (r < n) {
9            if (nums[r] == 0)
10                k--;
11            if (k < 0) {
12                if (nums[l] == 0)
13                    k++;
14                l++;
15            }
16            ans = max(ans, r - l + 1);
17            r++;
18        }
19        return ans;
20    }
21};