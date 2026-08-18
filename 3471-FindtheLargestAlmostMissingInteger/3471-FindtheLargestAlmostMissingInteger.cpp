// Last updated: 8/18/2026, 12:35:34 PM
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        int n = nums.size();
5        int ans = -1;
6        unordered_map<int, int> freq;
7        unordered_map<int, int> windows;
8        for (int i = 0; i < k; i++) {
9            freq[nums[i]]++;
10        }
11        for (auto it : freq) {
12            windows[it.first]++;
13        }
14        int l = 0, r = k;
15        while (r < n) {
16            freq[nums[l]]--;
17            if (freq[nums[l]] == 0)
18                freq.erase(nums[l]);
19            freq[nums[r]]++;
20            for (auto it : freq) {
21                windows[it.first]++;
22            }
23            l++;
24            r++;
25        }
26        for (auto it : windows) {
27            if (it.second == 1)
28                ans = max(ans, it.first);
29        }
30        return ans;
31    }
32};