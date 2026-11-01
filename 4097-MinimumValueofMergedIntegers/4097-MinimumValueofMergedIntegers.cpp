// Last updated: 11/1/2026, 8:57:35 PM
1class Solution {
2public:
3    int minMergedInteger(vector<int>& nums) {
4        int n = nums.size();
5        int ans = INT_MAX;
6        for (int i = 1; i < n; i+=2) {
7            string prev = to_string(nums[i - 1]);
8            string curr = to_string(nums[i]);
9            string number = prev + curr;
10            int a = stoi(number);
11            ans = min(ans, a);
12        }
13        return ans;
14    }
15};