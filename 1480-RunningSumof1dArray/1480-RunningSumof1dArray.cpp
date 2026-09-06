// Last updated: 9/6/2026, 5:08:13 PM
1class Solution {
2public:
3    vector<int> runningSum(vector<int>& nums) {
4
5        int n = nums.size();
6        vector<int> result;
7        int sum = 0;
8        for(int i = 0 ;i < n; i++) {
9
10            sum+=nums[i];
11            result.push_back(sum);
12        }
13        return result;
14    }
15};