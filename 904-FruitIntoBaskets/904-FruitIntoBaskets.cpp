// Last updated: 7/19/2026, 11:44:12 PM
1class Solution {
2public:
3    int totalFruit(vector<int>& fruits) {
4        int l = 0;
5        int r = 0;
6        unordered_map<int, int> mpp;
7        int ans = 0;
8        int n = fruits.size();
9        while (r < n) {
10            mpp[fruits[r]]++;
11            while (mpp.size() > 2) {
12                mpp[fruits[l]]--;
13                if (mpp[fruits[l]] == 0)
14                    mpp.erase(fruits[l]);
15                l++;
16            }
17
18            ans = max(ans, r - l + 1);
19            r++;
20        }
21        return ans;
22    }
23};