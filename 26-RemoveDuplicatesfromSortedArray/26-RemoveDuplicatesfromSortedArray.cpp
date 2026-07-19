// Last updated: 7/20/2026, 1:04:11 AM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int j = 0;
5        int prev = -1;
6        for (int i = 1; i < nums.size(); i++) {
7            if (nums[j] != nums[i]) {
8                nums[j + 1] = nums[i];
9                j++;
10            }
11        }
12        return j + 1;
13    }
14};