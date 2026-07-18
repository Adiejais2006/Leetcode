// Last updated: 7/18/2026, 2:26:27 PM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int mini = INT_MAX;
5        int maxi = INT_MIN;
6        for (auto it : nums) {
7            mini = min(it, mini);
8            maxi = max(maxi, it);
9        }
10
11        return gcd(mini, maxi);
12    }
13};