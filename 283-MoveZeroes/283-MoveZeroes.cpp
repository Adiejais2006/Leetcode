// Last updated: 7/20/2026, 1:07:47 AM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int i = 0;
5        for (int j = 0; j < nums.size(); j++) {
6            if (nums[j] != 0) {
7                swap(nums[j], nums[i]);
8                i++;
9            }
10        }
11    }
12};