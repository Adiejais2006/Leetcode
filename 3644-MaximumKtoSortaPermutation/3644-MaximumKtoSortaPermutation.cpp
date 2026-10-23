// Last updated: 10/23/2026, 12:16:09 PM
1class Solution {
2public:
3    int sortPermutation(vector<int>& nums) {
4        int k = -1;
5        for (int i = 0; i < nums.size(); i++)
6            if (nums[i] != i) {
7                k &= nums[i];
8                if (k == 0)
9                    return 0;
10            }
11        return max(k, 0);
12    }
13};