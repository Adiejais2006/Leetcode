// Last updated: 9/24/2026, 8:56:13 PM
1class Solution {
2public:
3    int deleteAndEarn(vector<int>& nums) {
4        int mx = *max_element(nums.begin(), nums.end());
5        vector<int> gain(mx + 1, 0);
6        for (int x : nums) {
7            gain[x] += x;
8        }
9
10        if (mx == 0)
11            return 0;
12        int prev2 = gain[0]; 
13        int prev = gain[1];   
14        for (int i = 2; i <= mx; i++) {
15            int notpick = prev;
16            int pick = gain[i] + prev2;
17            int curr = max(pick, notpick);
18            prev2 = prev;
19            prev = curr;
20        }
21        return prev;
22    }
23};