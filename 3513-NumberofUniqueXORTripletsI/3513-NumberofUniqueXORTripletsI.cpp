// Last updated: 7/24/2026, 12:11:17 AM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5
6        if (n <= 2) return n;
7
8        int mask = 0;
9        for (int num : nums) {
10            mask |= num;
11        }
12
13        return mask + 1;
14    }
15};