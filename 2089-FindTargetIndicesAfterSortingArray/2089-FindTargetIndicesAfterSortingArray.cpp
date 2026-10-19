// Last updated: 10/19/2026, 11:04:26 AM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        int less = 0, equal = 0;
5        for (int x : nums) {
6            if (x < target) less++;
7            else if (x == target) equal++;
8        }
9        vector<int> ans;
10        for (int i = 0; i < equal; i++)
11            ans.push_back(less + i);
12
13        return ans;
14    }
15};