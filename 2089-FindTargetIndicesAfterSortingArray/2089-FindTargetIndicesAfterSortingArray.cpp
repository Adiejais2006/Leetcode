// Last updated: 8/5/2026, 5:04:08 PM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int less = 0, equal = 0;
5
6        for (int x : nums) {
7            if (x < target) less++;
8            else if (x == target) equal++;
9        }
10
11        vector<int> ans;
12        for (int i = 0; i < equal; i++)
13            ans.push_back(less + i);
14
15        return ans;
16    }
17};