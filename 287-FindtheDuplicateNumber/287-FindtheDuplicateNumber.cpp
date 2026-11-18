// Last updated: 11/18/2026, 1:50:48 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int slow = 0;
5        int fast = 0;
6        do {
7            slow = nums[slow];
8            fast = nums[nums[fast]];
9        } while (slow != fast);
10        slow = 0;
11        while (slow != fast) {
12            slow = nums[slow];
13            fast = nums[fast];
14        }
15        return slow;
16    }
17};