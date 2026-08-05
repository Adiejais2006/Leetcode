// Last updated: 8/5/2026, 4:52:10 PM
1class Solution {
2public:
3    int smallestEqual(vector<int>& nums) {
4        int ans = -1;
5        for (int i = 0; i < nums.size(); i++) {
6            if (i % 10 == nums[i]) {
7                ans = i;
8                break;
9            }
10        }
11        return ans;
12    }
13};