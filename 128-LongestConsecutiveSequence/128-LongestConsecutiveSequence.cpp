// Last updated: 10/18/2026, 6:30:21 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        if(nums.empty())return 0 ;
5        unordered_set<int> st;
6        for (auto it : nums) {
7            st.insert(it);
8        }
9        int ans = 0;
10        for (auto it : nums) {
11            int el = it;
12            int cnt = 0;
13            if (!st.count(el - 1)) {
14                while (st.count(el + 1)) {
15                    cnt++;
16                    el++;
17                }
18            }
19            ans = max(ans, cnt);
20        }
21
22        return ans+1;
23    }
24};